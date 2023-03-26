#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "SceneManager.h"
#include "GameObject.h"
class Game
{
public:
	Game(int w, int h);
	void initGameLoop();
	GameManager gm;
	SceneManager sm;
	Renderer rend;
	sf::RenderWindow window;
	std::vector<GameObject*> gameObjects;
private:
	void processInput();
	void update();
};