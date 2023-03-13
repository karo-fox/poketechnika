#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene();
	void loadTextures();
	void draw(sf::RenderWindow& window);
};