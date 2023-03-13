#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "SceneManager.h"
class Game
{
public:
	Game();
	void InitGameLoop(int width, int height);
	GameManager gm;
	SceneManager sm;
private:
	void ProcessInput(sf::RenderWindow& window);
	void GameUpdate();
};