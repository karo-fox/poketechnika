#include "Renderer.h"
#include <SFML/Graphics.hpp>

Renderer::Renderer(sf::RenderWindow& w) : window(w) {}

void Renderer::draw(sf::Sprite s)
{
	window.draw(s);
}