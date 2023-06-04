#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Player.h"
class Renderer
{
	sf::RenderWindow& window;
	float scale;
public:
	void setScale();
	void rendClear();
	void rendDisplay();
	void draw(sf::Sprite s);
	void draw(Tile& tile, sf::Vector2f offset);
	void draw(Player& player);
	Renderer(sf::RenderWindow& w);
};