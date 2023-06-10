#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Map.h"
#include "Camera.h"
#include "Button.h"
#include "Pokemon.h"
#include "PokemonTypes.h"

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

	void draw(Drawable& drawable, float scale_rate = 1.0);
	void draw(Drawable& drawable, sf::Vector2f offset);
	void draw(Map& map, const Camera& cam);
	void draw(Button& button);
	void draw(Pokemon& pokemon, Side side);
};