#include "BattleScene.h"
#include <iostream>

BattleScene::BattleScene()
	: Scene{},
	background{ "assets/textures/background_battle.png", sf::Vector2f{0, 0}, true }
{
	std::vector<Button> buttons{
		// TODO buttons (attack / catch / change / rum) (move 1 / move 2 / move 3 / move 4)
		Button{"Start", Action::ChangeSceneToGame, sf::Vector2f{64, 64} },
		Button{"Close", Action::Close, sf::Vector2f{64, 128} },
	};
	ui = UI{ buttons };
	std::cout << "Created battle scene" << '\n';
}

void BattleScene::update(float time_elapsed, const InputHandler& ih) {
	ui.update(time_elapsed, ih);
}

void BattleScene::render(Renderer& renderer) {
	renderer.draw(background);
	for (auto& button : ui._buttons) {
		renderer.draw(button);
	}
}
