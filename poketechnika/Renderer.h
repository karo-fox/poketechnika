#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
class Renderer
{
	sf::RenderWindow& window;
	float scale;
public:
	void setScale();
	void rendClear();
	void rendDisplay();
	void draw(sf::Sprite s);
	void draw(Tile& tile, sf::Vector2i offset);
	Renderer(sf::RenderWindow& w);
};