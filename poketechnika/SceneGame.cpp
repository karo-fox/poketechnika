#include "SceneGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>

SceneGame::SceneGame()
{
	std::cout << "Created SceneGame" << std::endl;
}

void SceneGame::LoadTextures()
{
	backgroundTexture.loadFromFile(texturesPath+"background_game.png");
	background.setTexture(backgroundTexture);
	std::cout << "Loaded game textures" << std::endl;
}

void SceneGame::DrawScene(sf::RenderWindow& window) {
	window.draw(background);
}