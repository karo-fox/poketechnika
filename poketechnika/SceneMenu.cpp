#include "SceneMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

SceneMenu::SceneMenu()
{
	std::cout << "Created SceneMenu" << std::endl;
}

void SceneMenu::LoadTextures()
{
	backgroundTexture.loadFromFile(texturesPath+"background_menu.png");
	background.setTexture(backgroundTexture);
	std::cout << "Loaded mainmenu textures" << std::endl;
}

void SceneMenu::DrawScene(sf::RenderWindow& window) {
	window.draw(background);
}