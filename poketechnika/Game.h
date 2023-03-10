#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public:
	void InitGameLoop(int width, int height);
private:
	void ProcessInput(sf::RenderWindow& window);
	void GameUpdate();
	void Render(sf::RenderWindow& window);
};