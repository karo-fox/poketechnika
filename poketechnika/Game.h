#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "SceneManager.h"
#include "GameObjectsManager.h"
#include <vector>
class Game
{
public:
	Game(int w, int h, bool fullscreen);
	void initGameLoop();
	GameManager gm;
	SceneManager sm;
	Renderer rend;
	GameObjectsManager gom;
	sf::RenderWindow window;
private:
	void processInput();
	void update();
};