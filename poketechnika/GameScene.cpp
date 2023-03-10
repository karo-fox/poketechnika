#include "GameScene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameScene::GameScene()
{
	std::cout << "Created SceneGame" << std::endl;
}

void GameScene::loadTextures()
{
	backgroundTexture.loadFromFile(texturesPath+"background_game.png");
	background.setTexture(backgroundTexture);
	std::cout << "Loaded game textures" << std::endl;
}

void GameScene::draw(sf::RenderWindow& window) {
	window.draw(background);
}