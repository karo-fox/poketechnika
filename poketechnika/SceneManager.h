#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

enum class state { MAINMENU, GAME, BATTLE, INTRO, ERROR };

class SceneManager
{
	Scene* currScene;
	state scene;
public:
	SceneManager();
	virtual ~SceneManager();
	void renderScene(sf::RenderWindow& window);
	void changeScene(state change);
	state getCurrentScene();
};