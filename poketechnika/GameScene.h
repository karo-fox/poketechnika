#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene(sf::RenderWindow& w);
	void loadTextures();
	void draw();
};