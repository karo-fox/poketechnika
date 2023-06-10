#include "BossScene.h"

BossScene::BossScene() : background{ "assets/textures/background_boss.png", sf::Vector2f{0,0}, true }
{
	std::vector<Button> buttons{
		Button{"Return", Action::ChangeSceneToGame, sf::Vector2f{440, 430 }},
		Button{"Fight", Action::ChangeSceneToBattle, sf::Vector2f{740, 430}}
	};
	ui = UI{ buttons };
}

void BossScene::update(float elapsed_time, InputHandler& ih)
{
	ui.select();
	ui.update(elapsed_time, ih);
}

void BossScene::render(Renderer& renderer)
{
	renderer.draw(background);
	for (auto& button : ui._buttons) {
		renderer.draw(button);
	}
}


