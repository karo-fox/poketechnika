#pragma once
#include <SFML/Graphics.hpp>
class Renderer
{
	sf::RenderWindow& window;
	float scale;
public:
	void setScale();
	void rendClear();
	void rendDisplay();
	void draw(sf::Sprite s);
	Renderer(sf::RenderWindow& w);
};