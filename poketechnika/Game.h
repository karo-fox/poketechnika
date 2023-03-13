#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "SceneManager.h"
class Game
{
public:
	Game();
	void initGameLoop(int width, int height);
	GameManager gm;
	SceneManager sm;
private:
	void processInput(sf::RenderWindow& window);
	void update();
};