#pragma once
#include "Scene.h"
class GameScene : public Scene
{
public:
	GameScene(Renderer* rend);
	void loadTextures();
	void draw();
};