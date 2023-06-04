#include "Renderer.h"
#include <SFML/Graphics.hpp>

Renderer::Renderer(sf::RenderWindow& w) : window(w), scale(1.0) {
}

void Renderer::setScale() 
{
	scale = window.getSize().x / 1280.0f;
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

void Renderer::draw(Tile& tile, sf::Vector2f offset)
{
	sf::Sprite s = tile.getSprite();
	s.setPosition(sf::Vector2f(tile.getPosition() - offset));
	window.draw(s);
}

void Renderer::draw(Player& player)
{
	player.s.setPosition(sf::Vector2f(player.getPosition()));
	window.draw(player.s);
}