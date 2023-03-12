#pragma once
#include "Scene.h"
class SceneGame : public Scene
{
public:
	SceneGame();
	void LoadTextures();
	void DrawScene(sf::RenderWindow& window);
};