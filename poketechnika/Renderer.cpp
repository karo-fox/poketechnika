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

sf::RenderWindow& Renderer::getWindow() {
	return window;
}

void Renderer::draw(sf::Sprite s)
{
	s.setScale(scale, scale);
	window.draw(s);
}

//void Renderer::draw(Tile& tile, sf::Vector2f offset)
//{
//	sf::Sprite s = tile.getSprite();
//	s.setPosition(sf::Vector2f(tile.getPosition() - offset));
//	window.draw(s);
//}
//
//void Renderer::draw(Player& player)
//{
//	player.s.setPosition(sf::Vector2f(player.getPosition()));
//	window.draw(player.s);
//}

void Renderer::draw(Drawable& drawable) {
	drawable.sprite.setPosition(drawable.position);
	window.draw(drawable.sprite);
}

void Renderer::draw(Map& map, const Camera& cam) {
	for (int i = 0; i < map.layers.size(); i++)
	{
		for (int j = 0; j < map.layers[i].size(); j++)
		{
			for (int k = 0; k < map.layers[i][j].size(); k++)
			{
				if (cam.isWithinCamera(map.layers[i][j][k].position + sf::Vector2f(63, 63)))
					draw(map.layers[i][j][k]);
			}
		}
	}
}

