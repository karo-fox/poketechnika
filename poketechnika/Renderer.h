#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Map.h"
#include "Camera.h"
#include "Button.h"
#include "ImageButton.h"
#include "Text3Button.h"
#include "Bar.h"
#include "Pokemon.h"
#include "PokemonTypes.h"
#include "TextArea.h"

class Renderer
{
	sf::RenderWindow& window;
	float scale;
public:
	Renderer(sf::RenderWindow& w);

	// set's the renderer scale accotrding to chosen window
	void setScale();
	// Clears the screen
	void rendClear();
	// Displays all elements on screen
	void rendDisplay();
	// Returns window
	sf::RenderWindow& getWindow();

	// Draws Drawable on screen
	void draw(Drawable& drawable, float scale_rate = 1.0);
	// Draws Drawable on screen on offsetted position
	void draw(Drawable& drawable, sf::Vector2f offset);
	// Draws map on screen
	void draw(Map& map, const Camera& cam);
	// Draws Button on screen
	void draw(Button& button, float scale_rate = 1.0);
	// Draws TextArea on screen
	void draw(TextArea& textArea);
	// Draws ImageButton on screen
	void draw(ImageButton& button, float scale_rate = 1.0);
	// Draws Text3Button on screen
	void draw(Text3Button& button, float scale_rate = 1.0);
	// Draws Bar on screen
	void draw(Bar& bar, float scale_rate = 1.0);
	// Draws Pokemon on screen
	void draw(Pokemon& pokemon, Side side);
};