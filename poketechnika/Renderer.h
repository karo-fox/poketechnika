#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Map.h"
#include "Camera.h"
#include "Button.h"
#include "ImageButton.h"
#include "Pokemon.h"
#include "PokemonTypes.h"
#include "TextArea.h"

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
	void draw(Button& button, float scale_rate = 1.0);
	void draw(TextArea& textArea);
	void draw(ImageButton& button, float scale_rate = 1.0);
	void draw(Pokemon& pokemon, Side side);
};