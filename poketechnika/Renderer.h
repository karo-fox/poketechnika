#pragma once
#include <SFML/Graphics.hpp>
class Renderer
{
	sf::RenderWindow& window;
public:
	void draw(sf::Sprite s);
	Renderer(sf::RenderWindow& w);
};