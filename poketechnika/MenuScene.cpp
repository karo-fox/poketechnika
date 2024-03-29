#include <iostream>
#include <vector>
#include "MenuScene.h"
#include "Button.h"

MenuScene::MenuScene() 
	: Scene{},
	background{ "assets/textures/background_menu.png", sf::Vector2f{0, 0}, true }
{
	std::vector<std::shared_ptr<Button>> buttons{
		std::make_shared<Button>(Button{"Start", Action::ChangeSceneToGame, sf::Vector2f{592, 360} }),
		std::make_shared<Button>(Button{"Close", Action::Close, sf::Vector2f{592, 424} }),
	};
	ui = UI{ buttons };
	std::cout << "Created menu scene" << '\n';
}

void MenuScene::update(float time_elapsed, InputHandler& ih) {
	ui.select();
	ui.update(time_elapsed, ih);
}

void MenuScene::render(Renderer& renderer) {
	renderer.draw(background);
	for (auto& button : ui._buttons) {
		renderer.draw(*button);
	}
}
