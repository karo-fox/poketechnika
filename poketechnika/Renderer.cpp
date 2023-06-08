#include "Renderer.h"

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

void Renderer::draw(Button& button) {
	draw(button);
	button.text.setPosition(button.position.x + 3, button.position.y + 3);
	window.draw(button.text);
}
