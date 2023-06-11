#include "BattleScene.h"
#include "PokemonTable.h"
#include "Exception.h"
#include "database.h"
#include <iostream>
#include <pugixml.hpp>

const char* POKEMON_FILE_PATH = "data/pokemon.xml";
const char* PLAYER_TEAM_FILE_PATH = "data/player_team.xml";

BattleScene::BattleScene()
	: Scene{},
	background{ "assets/textures/background_battle.png", sf::Vector2f{0, 0}, true },
	menu(BattleMenu::MAIN), buttonRange{ 0,4 }, pokemonTemplate{}, currentTurn(Turn::PLAYER),
	battleLog("Log walki", sf::Vector2f(0,0))
{
	// UI
	std::vector<Button> buttons{
		// Main menu
		Button{"Attack", Action::AttackMenu, sf::Vector2f{500, 625} },
		Button{"Pokemon", Action::PokemonMenu, sf::Vector2f{700, 625} },
		Button{"Catch", Action::Catch, sf::Vector2f{900, 625} },
		Button{"Run", Action::Run, sf::Vector2f{1100, 625} },
		// Attack
		Button{"Attack1", Action::Close, sf::Vector2f{500, 625 } },
		Button{"Attack2", Action::Close, sf::Vector2f{700, 625 } },
		Button{"Attack3", Action::Close, sf::Vector2f{900, 625 } },
		Button{"Attack4", Action::Close, sf::Vector2f{1100, 625 } },
		// Pokemon
		Button{"Pokemon1", Action::Close, sf::Vector2f{100, 625 } },
		Button{"Pokemon2", Action::Close, sf::Vector2f{300, 625 } },
		Button{"Pokemon3", Action::Close, sf::Vector2f{500, 625 } },
		Button{"Pokemon4", Action::Close, sf::Vector2f{700, 625 } },
		Button{"Pokemon5", Action::Close, sf::Vector2f{900, 625 } },
		Button{"Pokemon6", Action::Close, sf::Vector2f{1100, 625 } },
	};
	ui = UI{ buttons };

	// Pokemon
	load_pokemon();

	load_player_team();
	playerTeam[0].setActive(true);

	enemyTeam[0] = pokemonTemplate[1];
	enemyTeam[0].setActive(true);
	enemyTeam[1] = pokemonTemplate[0];
	enemyTeam[2] = pokemonTemplate[0];
	enemyTeam[3] = pokemonTemplate[0];
	enemyTeam[4] = pokemonTemplate[0];
	enemyTeam[5] = pokemonTemplate[0];

	std::cout << "Created battle scene" << '\n';
}

void BattleScene::setRandomEnemy(InputHandler& ih)
{
	enemyTeam[0] = pokemonTemplate[ih.randomizer(1, pokemonTemplate.size()-1)];
	enemyTeam[0].setActive(true);
	isCatchable = true;
}

void BattleScene::load_pokemon()
{
	try {
		pugi::xml_document pokemon_file = load_xml_file(POKEMON_FILE_PATH);
		pugi::xml_node pokemon_node = pokemon_file.child("pokemon");

		pokemonTemplate = {
			{0, Pokemon()},
		};

		int i = 1;
		for (auto& nodes : pokemon_node.children())
		{
			Pokemon poke{};
			poke.load(nodes);
			pokemonTemplate.insert({i, poke });
			i++;
		}
	}
	catch (const Exception& e) {
		std::cout << e.what() << '\n';
	}
}

void BattleScene::load_player_team() {
	try {
		pugi::xml_document player_team_file = load_xml_file(PLAYER_TEAM_FILE_PATH);
		pugi::xml_node player_team_node = player_team_file.child("player_team");

		int idx{};
		for (auto& pokemon_node : player_team_node.children()) {
			Pokemon pokemon{};
			pokemon.load(pokemon_node);
			playerTeam[idx] = pokemon;
			idx++;
		}

	}
	catch (const Exception& e) {
		std::cout << e.what() << '\n';
	}
}

void BattleScene::save_player_team() {
	try {
		pugi::xml_document player_team_file = load_xml_file(PLAYER_TEAM_FILE_PATH);
		pugi::xml_node player_team_node = player_team_file.child("player_team");

		int idx{};
		for (auto& pokemon_node : player_team_node.children()) {
			playerTeam[idx].save(pokemon_node);
			idx++;
		}

		player_team_file.save_file(PLAYER_TEAM_FILE_PATH);
	}
	catch (const Exception& e) {
		std::cout << e.what() << '\n';
	}
}

void BattleScene::update(float time_elapsed, InputHandler& ih) {
	setMenuType(ih); // Change menu type
	ui.update(time_elapsed, ih, buttonRange[0], buttonRange[1] - 1); // Update ui (button switching, click)
	
	if (currentTurn == Turn::PLAYER)
	{
		if (ih.get_action(Action::Catch)) {
			if (isCatchable) {
				// TODO: percent chance with hp and lvl variables
				battleLog.addText("\nNie udalo sie!");
			}
			else {
				// Show Nie mo¿esz tego zrobiæ!
				battleLog.addText("\nNie mozesz tego zrobic!");
			}
		}
		if (ih.get_action(Action::Run)) {
			//TODO: percent chance with visibility in battlelog
			ih.add_action(Action::ChangeSceneToGame);
			save_player_team();
		}
	}
	else
	{
		// Enemy mechanic
	}
}

void BattleScene::render(Renderer& renderer) {
	// Background
	renderer.draw(background);
	
	// Buttons
	int k = 0;
	for (auto& button : ui._buttons) {
		if(k < buttonRange[1] && k >= buttonRange[0]) renderer.draw(button);
		k++;
	}

	// TODO: healthbars, Pokemon names, (or animations xD)
	for (int i = 0; i < 6; i++)
	{
		if (playerTeam[i].isActive()) renderer.draw(playerTeam[i], Side::back);
		if (enemyTeam[i].isActive()) renderer.draw(enemyTeam[i], Side::front);
	}
	renderer.draw(battleLog);
}

void BattleScene::setMenuType(InputHandler& ih)
{
	if (menu == BattleMenu::MAIN)
	{
		if (ih.get_action(Action::PokemonMenu)) {
			menu = BattleMenu::POKEMON;
			buttonRange[0] = 8;
			buttonRange[1] = 14;
		}
		else if (ih.get_action(Action::AttackMenu)) {
			menu = BattleMenu::MOVES;
			buttonRange[0] = 4;
			buttonRange[1] = 8;
		}
	}
	else
	{
		if (ih.get_action(Action::Exit)) {
			menu = BattleMenu::MAIN;
			buttonRange[0] = 0;
			buttonRange[1] = 4;
			ui.resetSelectButton();
		}
	}
}