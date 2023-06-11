#include "BattleScene.h"
#include "PokemonTable.h"
#include "Exception.h"
#include "database.h"
#include "ImageButton.h"
#include "Text3Button.h"
#include <iostream>
#include <pugixml.hpp>

const char* POKEMON_FILE_PATH = "data/pokemon.xml";
const char* PLAYER_TEAM_FILE_PATH = "data/player_team.xml";

BattleScene::BattleScene()
	: Scene{},
	background{ "assets/textures/background_battle.png", sf::Vector2f{0, 0}, true },
	menu(BattleMenu::MAIN), buttonRange{ 0,4 }, pokemonTemplate{}, currentTurn(Turn::PLAYER),
	battleLog("Log walki", sf::Vector2f(0,0)), active_player_pokemon_idx{}
{
	// UI
	std::vector<std::shared_ptr<Button>> buttons{
		// Main menu
		std::make_shared<Button>(Button{"Attack", Action::AttackMenu, sf::Vector2f{400, 625} }),
		std::make_shared<Button>(Button{"Pokemon", Action::PokemonMenu, sf::Vector2f{600, 625} }),
		std::make_shared<Button>(Button{"Catch", Action::Catch, sf::Vector2f{800, 625} }),
		std::make_shared<Button>(Button{"Run", Action::Run, sf::Vector2f{1000, 625} }),
		// Attack
		std::make_shared<Text3Button>(Text3Button{"Attack1", "type", "power", Action::Close, sf::Vector2f{250, 600}}),
		std::make_shared<Text3Button>(Text3Button{"Attack2", "type", "power", Action::Close, sf::Vector2f{500, 600}}),
		std::make_shared<Text3Button>(Text3Button{"Attack3", "type", "power", Action::Close, sf::Vector2f{750, 600}}),
		std::make_shared<Text3Button>(Text3Button{"Attack4", "type", "power", Action::Close, sf::Vector2f{1000, 600}}),

		// Pokemon
		std::make_shared<ImageButton>(ImageButton{ Action::Close, sf::Vector2f{50, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Close, sf::Vector2f{250, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Close, sf::Vector2f{450, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Close, sf::Vector2f{650, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Close, sf::Vector2f{850, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Close, sf::Vector2f{1050, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
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
		if (ih.get_action(Action::PokemonMenu)) {
			menu = BattleMenu::POKEMON;
			buttonRange[0] = 8;
			buttonRange[1] = 14;
			for (int i = buttonRange[0]; i < buttonRange[1]; i++) {
				ui._buttons.at(i) = std::make_shared<ImageButton>(
					ImageButton{
						ui._buttons.at(i)->click(), 
						ui._buttons.at(i)->position, 
						playerTeam[i-buttonRange[0]].front.file
					}
				);
			}
		}
		else if (ih.get_action(Action::AttackMenu)) {
			menu = BattleMenu::MOVES;
			buttonRange[0] = 4;
			buttonRange[1] = 8;
			for (int i = buttonRange[0]; i < buttonRange[1]; i++) {
				auto move_data = playerTeam[active_player_pokemon_idx].getMoveData((i - buttonRange[0])+1);
				ui._buttons.at(i) = std::make_shared<Text3Button>(
					Text3Button{
						move_data.at(0), move_data.at(1), move_data.at(2),
						ui._buttons.at(i)->click(), ui._buttons.at(i)->position
					}
				);
			}
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
	// Update ui (button switching, click)
	ui.update(time_elapsed, ih, buttonRange[0], buttonRange[1] - 1);
	// Running from battle
	if (ih.get_action(Action::Run)) {
		//TODO: percent chance with visibility in battlelog
		ih.add_action(Action::ChangeSceneToGame);
		save_player_team();
	}
}

void BattleScene::render(Renderer& renderer) {
	// Background
	renderer.draw(background);
	
	// Buttons
	int i = 0;
	for (auto& button : ui._buttons) {
		if (i < buttonRange[1] && i >= buttonRange[0]) {
			switch (menu) {
			case BattleMenu::POKEMON:
				renderer.draw(dynamic_cast<ImageButton&>(*button), 2.0);
				break;
			case BattleMenu::MOVES:
				renderer.draw(dynamic_cast<Text3Button&>(*button), 2.5);
				break;
			default:
				renderer.draw(*button, 2.0);
				break;
			}
		}
		i++;
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