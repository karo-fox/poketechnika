#include "MenuScene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//MenuScene::MenuScene(Renderer* rend) : Scene(rend)
//{
//	std::cout << "Created SceneMenu" << std::endl;
//}
//
//void MenuScene::loadTextures()
//{
//	backgroundTexture.loadFromFile(texturesPath+"background_menu.png");
//	background.setTexture(backgroundTexture);
//	std::cout << "Loaded mainmenu textures" << std::endl;
//}
//
//void MenuScene::draw() {
//	renderer->draw(background);
//}

MenuScene::MenuScene() 
	: Scene{}, ih{ {}, {} }, 
	ui{}, background{ "assets/textures/background_menu.png", sf::Vector2f{0, 0} }
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
