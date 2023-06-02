#include "GameScene.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameManager* GameScene::gm = nullptr;

GameScene::GameScene(Renderer* rend) : Scene(rend)
{
	std::cout << "Created SceneGame" << std::endl;
}

void GameScene::setGMPtr(GameManager* ptr) {
	gm = ptr;
}

void GameScene::loadTextures()
{
	backgroundTexture.loadFromFile(texturesPath+"background_game.png");
	background.setTexture(backgroundTexture);
	std::cout << "Loaded game textures" << std::endl;
}

void GameScene::draw() {
	renderer->draw(background);

	//draw map
	for (int i = 0; i < gm->map.layers.size(); i++)
	{
		for (int j = 0; j < gm->map.layers[i].size(); j++)
		{
			for (int k = 0; k < gm->map.layers[i][j].size(); k++)
			{
				if(cam.isWithinCamera(gm->map.layers[i][j][k].getPosition() + sf::Vector2i(63, 63)))
					renderer->draw(gm->map.layers[i][j][k], cam.getPosition());
			}
		}
	}

	is_rendered = true;
}