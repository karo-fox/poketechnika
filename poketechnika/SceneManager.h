#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

enum class State { MAINMENU, GAME, BATTLE, INTRO, ERROR };

class SceneManager
{
	Scene* currScene;
	State scene;
	Renderer* rend;
public:
	SceneManager(Renderer* rend_);
	virtual ~SceneManager();
	void createFirstScene();
	void renderScene();
	void changeScene(State change);
	State getCurrentScene() const;
};