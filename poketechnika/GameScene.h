#pragma once
#include "Scene.h"
#include "GameManager.h"
class GameScene : public Scene
{
private:
	static GameManager* gm;
public:
	GameScene(Renderer* rend);
	void loadTextures();
	void draw();
	static void setGMPtr(GameManager* ptr);
};