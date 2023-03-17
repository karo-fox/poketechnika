#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

enum class state { MAINMENU, GAME, BATTLE, INTRO, ERROR };

class SceneManager
{
	Scene* currScene;
	state scene;
	sf::RenderWindow& window;
public:
	SceneManager(sf::RenderWindow& w);
	virtual ~SceneManager();
	void renderScene();
	void changeScene(state change);
	state getCurrentScene();
};