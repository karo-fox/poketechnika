#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Map.h"
#include "Camera.h"

class Renderer
{
	sf::RenderWindow& window;
	float scale;
public:
	void setScale();
	void rendClear();
	void rendDisplay();
	sf::RenderWindow& getWindow();

	void draw(sf::Sprite s);
	void draw(Drawable& drawable);
	void draw(Map& map, const Camera& cam);
	//void draw(Tile& tile, sf::Vector2f offset);
	//void draw(Player& player);
	Renderer(sf::RenderWindow& w);
};