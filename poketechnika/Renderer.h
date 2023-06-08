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
	Renderer(sf::RenderWindow& w);

	void setScale();
	void rendClear();
	void rendDisplay();
	sf::RenderWindow& getWindow();

	void draw(Drawable& drawable);
	void draw(Map& map, const Camera& cam);
};