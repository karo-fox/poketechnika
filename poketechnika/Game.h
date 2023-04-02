#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "SceneManager.h"
#include "GameObject.h"
#include <vector>
class Game
{
public:
	Game(int w, int h, bool fullscreen);
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