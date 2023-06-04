#pragma once
#include "Scene.h"
#include "State.h"
#include <SFML/Graphics.hpp>

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
	Scene getCurrentScene() const;
	State getSceneType() const;
};