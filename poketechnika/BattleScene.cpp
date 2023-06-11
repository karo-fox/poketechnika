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
	battleLog("Battle Log:", sf::Vector2f(0,0)), active_player_pokemon_idx{}
{
	// UI
	std::vector<std::shared_ptr<Button>> buttons{
		// Main menu
		std::make_shared<Button>(Button{"Attack", Action::AttackMenu, sf::Vector2f{400, 625} }),
		std::make_shared<Button>(Button{"Pokemon", Action::PokemonMenu, sf::Vector2f{600, 625} }),
		std::make_shared<Button>(Button{"Catch", Action::Catch, sf::Vector2f{800, 625} }),
		std::make_shared<Button>(Button{"Run", Action::Run, sf::Vector2f{1000, 625} }),
		// Attack
		std::make_shared<Text3Button>(Text3Button{"Attack1", "type", "power", Action::Attack1, sf::Vector2f{250, 600}}),
		std::make_shared<Text3Button>(Text3Button{"Attack2", "type", "power", Action::Attack2, sf::Vector2f{500, 600}}),
		std::make_shared<Text3Button>(Text3Button{"Attack3", "type", "power", Action::Attack3, sf::Vector2f{750, 600}}),
		std::make_shared<Text3Button>(Text3Button{"Attack4", "type", "power", Action::Attack4, sf::Vector2f{1000, 600}}),

		// Pokemon
		std::make_shared<ImageButton>(ImageButton{ Action::Pokemon1, sf::Vector2f{50, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Pokemon2, sf::Vector2f{250, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Pokemon3, sf::Vector2f{450, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Pokemon4, sf::Vector2f{650, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Pokemon5, sf::Vector2f{850, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
		std::make_shared<ImageButton>(ImageButton{ Action::Pokemon6, sf::Vector2f{1050, 625 }, "assets/textures/pokemon/Squirtle_front.png" }),
	};
	ui = UI{ buttons };

	// Pokemon
	load_pokemon();

	load_player_team();
	//playerTeam[0].setActive(true);
	for (int i = 0; i < 6; i++) if (playerTeam[i].isActive()) active_player_pokemon_idx = i;
	enemyTeam[0] = pokemonTemplate[0];
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
	enemyTeam[0].setLvl(ih.randomizer(1, 6));
	enemyTeam[0].setActive(true);
	isCatchable = true;
	battleLog.setText("Battle Log:");
	battleLog.addText("\nA wild " + enemyTeam[0].getName() + " appears!");
	currentTurn = Turn::PLAYER;
}

void BattleScene::setBossFight(InputHandler& ih)
{
	enemyTeam[0] = pokemonTemplate[11];
	enemyTeam[0].setLvl(5);
	enemyTeam[1] = pokemonTemplate[8];
	enemyTeam[1].setLvl(6);
	enemyTeam[2] = pokemonTemplate[10];
	enemyTeam[2].setLvl(7);
	enemyTeam[0].setActive(true);
	isCatchable = false;
	battleLog.setText("Battle Log:");
	battleLog.addText("\nBOSS FIGHT!!!");
	currentTurn = Turn::PLAYER;
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
			pokemonTemplate.insert({i, poke});
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
			if (pokemon.getName() != "NULL") playerTeam[idx] = pokemon;
			else playerTeam[idx] = Pokemon();
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
	int enemyPokemon = 0;
	for (enemyPokemon; enemyPokemon < 6; enemyPokemon++) if (enemyTeam[enemyPokemon].isActive()) break;
	if (currentTurn == Turn::PLAYER)
	{
		if (ih.get_action(Action::Attack1)) {
			float mod = playerTeam[active_player_pokemon_idx].getMove(1).getModifier(playerTeam[active_player_pokemon_idx].getMove(1).getType(), enemyTeam[enemyPokemon].getType1(), enemyTeam[enemyPokemon].getType2());
			float damage = playerTeam[active_player_pokemon_idx].getLvl()* mod * 5.0f * playerTeam[active_player_pokemon_idx].getMove(1).getPower();
			enemyTeam[enemyPokemon].reduceHP((int)damage);
			battleLog.addText("\n"+playerTeam[active_player_pokemon_idx].getName()+" used "+ playerTeam[active_player_pokemon_idx].getMove(1).getName() + " for "+ std::to_string((int)damage) + " damage!");
			currentTurn = Turn::ENEMY;
			ih.add_action(Action::Exit);
		}
		else if (ih.get_action(Action::Attack2)) {
			float mod = playerTeam[active_player_pokemon_idx].getMove(2).getModifier(playerTeam[active_player_pokemon_idx].getMove(2).getType(), enemyTeam[enemyPokemon].getType1(), enemyTeam[enemyPokemon].getType2());
			float damage = playerTeam[active_player_pokemon_idx].getLvl() * mod * 5.0f * playerTeam[active_player_pokemon_idx].getMove(2).getPower();
			enemyTeam[enemyPokemon].reduceHP((int)damage);
			battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + " used " + playerTeam[active_player_pokemon_idx].getMove(2).getName() + " for " + std::to_string((int)damage) + " damage!");
			currentTurn = Turn::ENEMY;
			ih.add_action(Action::Exit);
		}
		else if (ih.get_action(Action::Attack3)) {
			float mod = playerTeam[active_player_pokemon_idx].getMove(3).getModifier(playerTeam[active_player_pokemon_idx].getMove(3).getType(), enemyTeam[enemyPokemon].getType1(), enemyTeam[enemyPokemon].getType2());
			float damage = playerTeam[active_player_pokemon_idx].getLvl() * mod * 5.0f * playerTeam[active_player_pokemon_idx].getMove(3).getPower();
			enemyTeam[enemyPokemon].reduceHP((int)damage);
			battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + " used " + playerTeam[active_player_pokemon_idx].getMove(3).getName() + " for " + std::to_string((int)damage) + " damage!");
			currentTurn = Turn::ENEMY;
			ih.add_action(Action::Exit);
		}
		else if (ih.get_action(Action::Attack4)) {
			float mod = playerTeam[active_player_pokemon_idx].getMove(3).getModifier(playerTeam[active_player_pokemon_idx].getMove(4).getType(), enemyTeam[enemyPokemon].getType1(), enemyTeam[enemyPokemon].getType2());
			float damage = playerTeam[active_player_pokemon_idx].getLvl() * mod * 5.0f * playerTeam[active_player_pokemon_idx].getMove(4).getPower();
			enemyTeam[enemyPokemon].reduceHP((int)damage);
			battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + " used " + playerTeam[active_player_pokemon_idx].getMove(4).getName() + " for " + std::to_string((int)damage) + " damage!");
			currentTurn = Turn::ENEMY;
			ih.add_action(Action::Exit);
		}
		else if (ih.get_action(Action::Pokemon1)) {
			if (active_player_pokemon_idx != 0 && playerTeam[0].getName()!="NULL")
			{
				if (playerTeam[0].getHP() > 0)
				{
					battleLog.addText("\nCome back, " + playerTeam[active_player_pokemon_idx].getName() + "!");
					playerTeam[active_player_pokemon_idx].setActive(false);
					active_player_pokemon_idx = 0;
					playerTeam[active_player_pokemon_idx].setActive(true);
					battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + ", I choose you!");
					currentTurn = Turn::ENEMY;
					ih.add_action(Action::Exit);
				}
				else
				{
					battleLog.addText("\n" + playerTeam[0].getName() + " is unconscious!");
				}
			}
			else 
			{
				battleLog.addText("\nYou cannot do that!");
			}
		}
		else if (ih.get_action(Action::Pokemon2)) {
			if (active_player_pokemon_idx != 1 && playerTeam[1].getName() != "NULL")
			{
				if (playerTeam[0].getHP() > 0)
				{
					battleLog.addText("\nCome back, " + playerTeam[active_player_pokemon_idx].getName() + "!");
					playerTeam[active_player_pokemon_idx].setActive(false);
					active_player_pokemon_idx = 1;
					playerTeam[active_player_pokemon_idx].setActive(true);
					battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + ", I choose you!");
					currentTurn = Turn::ENEMY;
					ih.add_action(Action::Exit);
				}
				else
				{
					battleLog.addText("\n" + playerTeam[1].getName() + " is unconscious!");
				}
			}
			else
			{
				battleLog.addText("\nYou cannot do that!");
			}
		}
		else if (ih.get_action(Action::Pokemon3)) {
			if (active_player_pokemon_idx != 2 && playerTeam[2].getName() != "NULL")
			{
				if (playerTeam[0].getHP() > 0)
				{
					battleLog.addText("\nCome back, " + playerTeam[active_player_pokemon_idx].getName() + "!");
					playerTeam[active_player_pokemon_idx].setActive(false);
					active_player_pokemon_idx = 2;
					playerTeam[active_player_pokemon_idx].setActive(true);
					battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + ", I choose you!");
					currentTurn = Turn::ENEMY;
					ih.add_action(Action::Exit);
				}
				else
				{
					battleLog.addText("\n" + playerTeam[2].getName() + " is unconscious!");
				}
			}
			else
			{
				battleLog.addText("\nYou cannot do that!");
			}
		}
		else if (ih.get_action(Action::Pokemon4)) {
			if (active_player_pokemon_idx != 3 && playerTeam[3].getName() != "NULL")
			{
				if (playerTeam[0].getHP() > 0)
				{
					battleLog.addText("\nCome back, " + playerTeam[active_player_pokemon_idx].getName() + "!");
					playerTeam[active_player_pokemon_idx].setActive(false);
					active_player_pokemon_idx = 3;
					playerTeam[active_player_pokemon_idx].setActive(true);
					battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + ", I choose you!");
					currentTurn = Turn::ENEMY;
					ih.add_action(Action::Exit);
				}
				else
				{
					battleLog.addText("\n" + playerTeam[3].getName() + " is unconscious!");
				}
			}
			else
			{
				battleLog.addText("\nYou cannot do that!");
			}
		}
		else if (ih.get_action(Action::Pokemon5)) {
			if (active_player_pokemon_idx != 4 && playerTeam[4].getName() != "NULL")
			{
				if (playerTeam[0].getHP() > 0)
				{
					battleLog.addText("\nCome back, " + playerTeam[active_player_pokemon_idx].getName() + "!");
					playerTeam[active_player_pokemon_idx].setActive(false);
					active_player_pokemon_idx = 4;
					playerTeam[active_player_pokemon_idx].setActive(true);
					battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + ", I choose you!");
					currentTurn = Turn::ENEMY;
					ih.add_action(Action::Exit);
				}
				else
				{
					battleLog.addText("\n" + playerTeam[4].getName() + " is unconscious!");
				}
			}
			else
			{
				battleLog.addText("\nYou cannot do that!");
			}
		}
		else if (ih.get_action(Action::Pokemon6)) {
			if (active_player_pokemon_idx != 5 && playerTeam[5].getName() != "NULL")
			{
				if (playerTeam[0].getHP() > 0)
				{
					battleLog.addText("\nCome back, " + playerTeam[active_player_pokemon_idx].getName() + "!");
					playerTeam[active_player_pokemon_idx].setActive(false);
					active_player_pokemon_idx = 5;
					playerTeam[active_player_pokemon_idx].setActive(true);
					battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + ", I choose you!");
					currentTurn = Turn::ENEMY;
					ih.add_action(Action::Exit);
				}
				else
				{
					battleLog.addText("\n" + playerTeam[5].getName() + " is unconscious!");
				}
			}
			else
			{
				battleLog.addText("\nYou cannot do that!");
			}
		}
		else if (ih.get_action(Action::Catch)) {
			if (isCatchable) {
				// TODO: percent chance with hp and lvl variables

				bool success = false;
				for (int i = 0; i < 6; i++) {
					if (playerTeam[i].getName() == "NULL" && !success) {
						playerTeam[i] = enemyTeam[0];
						playerTeam[i].setActive(false);
						battleLog.addText("\nYou successfully catched a " + enemyTeam[0].getName() + "!");
						success = true;
						ih.add_action(Action::ChangeSceneToGame);
					}
				}
				if(!success) battleLog.addText("\nYour catch attempt failed!");
				currentTurn = Turn::ENEMY;
			}
			else {
				// Show Nie mo¿esz tego zrobiæ!
				battleLog.addText("\nYou cannot do that!");
			}
		}
		else if (ih.get_action(Action::Run)) {
			//TODO: percent chance with visibility in battlelog
			battleLog.addText("\nYou escaped from battle!");
			ih.add_action(Action::ChangeSceneToGame);
			for (int i = 0; i < 6; i++)
			{
				playerTeam[i].setHPToMax();
			}
			save_player_team();
		}
	}
	else
	{
		// Enemy turn
		int enemyPokemon = 0;
		for (enemyPokemon; enemyPokemon < 6; enemyPokemon++) if (enemyTeam[enemyPokemon].isActive()) break;\
		int attack = ih.randomizer(1, 4);
		float mod = enemyTeam[enemyPokemon].getMove(attack).getModifier(enemyTeam[enemyPokemon].getMove(attack).getType(), playerTeam[active_player_pokemon_idx].getType1(), playerTeam[active_player_pokemon_idx].getType2());
		float damage = enemyTeam[enemyPokemon].getLvl() * mod * 5.0f * enemyTeam[enemyPokemon].getMove(attack).getPower();
		playerTeam[active_player_pokemon_idx].reduceHP((int)damage);
		battleLog.addText("\n" + enemyTeam[enemyPokemon].getName() + " used " + enemyTeam[enemyPokemon].getMove(attack).getName() + " for " + std::to_string((int)damage) + " damage!");
		currentTurn = Turn::PLAYER;
	}
	// Check if fainted
	if (playerTeam[active_player_pokemon_idx].getHP() <= 0)
	{
		battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + " has fainted!");
		playerTeam[active_player_pokemon_idx].setActive(false);
		bool all = true;
		for (int i = 0; i < 6; i++) {
			if (playerTeam[i].getHP() > 0 && playerTeam[i].getName()!="NULL") {
				playerTeam[i].setActive(true);
				active_player_pokemon_idx = i;
				all = false;
				break;
			}
		}
		if (all) {
			playerTeam[0].setActive(true);
			active_player_pokemon_idx = 0;
			battleLog.addText("\nYou lose!");
			currentTurn = Turn::PLAYER;
			ih.add_action(Action::ChangeSceneToGame);
			for (int i = 0; i < 6; i++)
			{
				playerTeam[i].setHPToMax();
			}
			save_player_team();
		}
	}
	if (enemyTeam[enemyPokemon].getHP() <= 0)
	{
		battleLog.addText("\n" + enemyTeam[enemyPokemon].getName() + " has fainted!");
		enemyTeam[enemyPokemon].setActive(false);
		playerTeam[active_player_pokemon_idx].addXP(enemyTeam[enemyPokemon].getXP());
		if(playerTeam[active_player_pokemon_idx].checkForLvlUp()) battleLog.addText("\n" + playerTeam[active_player_pokemon_idx].getName() + " is now " + std::to_string(playerTeam[active_player_pokemon_idx].getLvl())+" level!");
		bool all = true;
		for (int i = 0; i < 6; i++) {
			if (enemyTeam[i].getHP() > 0 && enemyTeam[i].getName()!="NULL") {
				enemyTeam[i].setActive(true);
				enemyPokemon = i;
				all = false;
				break;
			}
		}
		if (all) {
			// PLAYER WINS
			currentTurn = Turn::PLAYER;
			battleLog.addText("\nYou win!");
			if (!isCatchable) ih.add_action(Action::WINGAME);
			else ih.add_action(Action::ChangeSceneToGame);
			for (int i = 0; i < 6; i++)
			{
				playerTeam[i].setHPToMax();
			}
			save_player_team();
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
	else
	{
		if (ih.get_action(Action::Exit)) {
			menu = BattleMenu::MAIN;
			buttonRange[0] = 0;
			buttonRange[1] = 4;
			ui.resetSelectButton(buttonRange[0]);
		}
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
			ui.resetSelectButton(buttonRange[0]);
		}
	}
}