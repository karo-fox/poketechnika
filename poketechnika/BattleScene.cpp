#include "BattleScene.h"
#include "PokemonTable.h"
#include <iostream>

BattleScene::BattleScene()
	: Scene{},
	background{ "assets/textures/background_battle.png", sf::Vector2f{0, 0}, true },
	menu(BattleMenu::MAIN), buttonRange{0,4}
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
	playerTeam[0] = pokemonTemplate[1];
	playerTeam[0].setActive(true);
	playerTeam[1] = pokemonTemplate[0];
	playerTeam[2] = pokemonTemplate[0];
	playerTeam[3] = pokemonTemplate[0];
	playerTeam[4] = pokemonTemplate[0];
	playerTeam[5] = pokemonTemplate[0];
	for (int i = 0; i < 5; i++) playerTeam[i].setOwner(true);
	enemyTeam[0] = pokemonTemplate[1];
	enemyTeam[0].setActive(true);
	enemyTeam[1] = pokemonTemplate[0];
	enemyTeam[2] = pokemonTemplate[0];
	enemyTeam[3] = pokemonTemplate[0];
	enemyTeam[4] = pokemonTemplate[0];
	enemyTeam[5] = pokemonTemplate[0];
	for (int i = 0; i < 5; i++) enemyTeam[i].setOwner(false);
	std::cout << "Created battle scene" << '\n';
}

void BattleScene::update(float time_elapsed, InputHandler& ih) {
	// Change menu type
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
	// Update ui (button switching, click)
	ui.update(time_elapsed, ih, buttonRange[0], buttonRange[1] - 1);
	// Running from battle
	if (ih.get_action(Action::Run)) {
		//TODO: percent chance with visibility in battlelog
		ih.add_action(Action::ChangeSceneToGame);
	}
}

void BattleScene::render(Renderer& renderer) {
	// Background
	renderer.draw(background);
	
	// Buttons
	int i = 0;
	for (auto& button : ui._buttons) {
		if(i < buttonRange[1] && i >= buttonRange[0]) renderer.draw(button);
		i++;
	}

	// TODO: Pokemons, healthbars, Pokemon names, BattleLog (or animations xD)
	for (int i = 0; i < 6; i++)
	{
		if (playerTeam[i].isActive()) renderer.draw(playerTeam[i]);
		if (enemyTeam[i].isActive()) renderer.draw(enemyTeam[i]);
	}
}