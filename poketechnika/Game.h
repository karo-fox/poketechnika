#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
class Game
{
public:
	Game();
	void InitGameLoop(int width, int height);
	GameManager gm;
private:
	void ProcessInput(sf::RenderWindow& window);
	void GameUpdate();
	void Render(sf::RenderWindow& window);
};