#include "Renderer.h"
#include <SFML/Graphics.hpp>

Renderer::Renderer(sf::RenderWindow& w) : window(w), scale(1.0) {
}

void Renderer::setScale() 
{
	scale = window.getSize().x / 1280.0;
}

void Renderer::rendClear() 
{
	window.clear();
}

void Renderer::rendDisplay()
{
	window.display();
}

void Renderer::draw(sf::Sprite s)
{
	s.setScale(scale, scale);
	window.draw(s);
}