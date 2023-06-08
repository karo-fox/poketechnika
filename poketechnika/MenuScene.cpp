#include <iostream>
#include "MenuScene.h"

MenuScene::MenuScene() 
	: Scene{}, ih{ {}, {} }, 
	background{ "assets/textures/background_menu.png", sf::Vector2f{0, 0} }
{
	std::cout << "Created menu scene" << '\n';
}

void MenuScene::update(float time_elapsed) {}

void MenuScene::process_input(sf::RenderWindow& window) {
	ih.reset_actions();
	ih.process_input(window);
}

void MenuScene::render(Renderer& renderer) {
	renderer.draw(background);
}
