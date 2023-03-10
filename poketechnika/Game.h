#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
class Game
{
public:
	Game();
	void InitGameLoop(int width, int height);
	State state_;
private:
	void ProcessInput(sf::RenderWindow& window);
	void GameUpdate();
	void Render(sf::RenderWindow& window);

};