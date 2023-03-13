#include "MenuScene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

MenuScene::MenuScene()
{
	std::cout << "Created SceneMenu" << std::endl;
}

void MenuScene::loadTextures()
{
	backgroundTexture.loadFromFile(texturesPath+"background_menu.png");
	background.setTexture(backgroundTexture);
	std::cout << "Loaded mainmenu textures" << std::endl;
}

void MenuScene::draw(sf::RenderWindow& window) {
	window.draw(background);
}