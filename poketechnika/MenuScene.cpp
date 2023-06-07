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

MenuScene::MenuScene() : Scene{}, ih {}, ui{} {}

void MenuScene::update(float time_elapsed) {}

void MenuScene::process_input(sf::RenderWindow& window) {
	ih.process_input(window);
}

void MenuScene::render(Renderer& renderer) {}
