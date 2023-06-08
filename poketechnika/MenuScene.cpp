#include <iostream>
#include <vector>
#include "MenuScene.h"
#include "Button.h"

std::vector<Button> buttons{
	Button{"test", Action::ChangeSceneToGame, sf::Vector2f{64, 64} }
};

MenuScene::MenuScene() 
	: Scene{},
	background{ "assets/textures/background_menu.png", sf::Vector2f{0, 0} }
{
	ui = UI{ buttons };
	std::cout << "Created menu scene" << '\n';
}

void MenuScene::update(float time_elapsed, const InputHandler& ih) {}

//void MenuScene::process_input(sf::RenderWindow& window) {
//	ih.reset_actions();
//	ih.process_input(window);
//}

void MenuScene::render(Renderer& renderer) {
	renderer.draw(background);
}
