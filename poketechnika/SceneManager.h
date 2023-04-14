#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

enum class state { MAINMENU, GAME, BATTLE, INTRO, ERROR };

class SceneManager
{
	Scene* currScene;
	state scene;
	Renderer* rend;
public:
	SceneManager(Renderer* rend_);
	virtual ~SceneManager();
	void createFirstScene();
	void renderScene();
	void changeScene(state change);
	state getCurrentScene();
};