#include "BattleScene.h"
#include <iostream>

BattleScene::BattleScene()
	: Scene{},
	background{ "assets/textures/background_battle.png", sf::Vector2f{0, 0}, true },
	menu(BattleMenu::MAIN)
{
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
	std::cout << "Created battle scene" << '\n';
}

void BattleScene::update(float time_elapsed, const InputHandler& ih) {
	// Update ui (button switching, click)
	int max = -1, min = -1;
	if (menu == BattleMenu::MAIN) {
		max = 3;
		min = 0;
	}
	else if (menu == BattleMenu::MOVES) {
		max = 7;
		min = 4;
	}
	else if (menu == BattleMenu::POKEMON) {
		max = 13;
		min = 8;
	}
	ui.update(time_elapsed, ih, min, max);
	// Change menu type
	if (menu == BattleMenu::MAIN)
	{
		if (ih.get_action(Action::PokemonMenu)) menu = BattleMenu::POKEMON;
		else if (ih.get_action(Action::AttackMenu)) menu = BattleMenu::MOVES;
	}
	else
	{
		if (ih.get_action(Action::Exit)) {
			menu = BattleMenu::MAIN;
		}
	}
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
	int max = -1, min = -1;
	if (menu == BattleMenu::MAIN){
		max = 4;
		min = 0;
	}
	else if (menu == BattleMenu::MOVES) {
		max = 8;
		min = 4;
	}
	else if (menu == BattleMenu::POKEMON) {
		max = 14;
		min = 8;
	}

	int i = 0;
	for (auto& button : ui._buttons) {
		if(i < max && i >= min) renderer.draw(button);
		i++;
	}

	// TODO: Pokemons, healthbars, Pokemon names, BattleLog (or animations xD)
}
