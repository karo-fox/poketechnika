#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& w) : window(w), scale(1.0) {
}

void Renderer::rendClear()
{
	window.clear();
}

void Renderer::rendDisplay()
{
	window.display();
}

void Renderer::draw(Drawable& drawable, float scale_rate) {
	if (drawable.isScalable()) {
		drawable.sprite.setScale(scale * scale_rate, scale * scale_rate);
		drawable.sprite.setPosition(drawable.position * scale);
	}
	else {
		drawable.sprite.setPosition(drawable.position);
	}
	
	window.draw(drawable.sprite);
}

void Renderer::draw(Drawable& drawable, sf::Vector2f offset) {
	if (drawable.isScalable()) drawable.sprite.setScale(scale, scale);
	drawable.sprite.setPosition(drawable.position - offset);
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
					draw(map.layers[i][j][k], cam.getPosition());
			}
		}
	}
}

void Renderer::draw(Button& button) {
	if (button.isScalable()) {
		button.sprite.setScale(scale, scale);
		button.sprite.setPosition(button.position * scale);
	}
	else {
		button.sprite.setPosition(button.position);
	}	
	window.draw(button.sprite);
	if (button.isScalable()) {
		button.text.setScale(scale, scale);
		button.text.setPosition(
			button.position.x * scale + 3, button.position.y * scale + 3
		);
	}
	else {
		button.text.setPosition(button.position.x + 3, button.position.y + 3);
	}
	window.draw(button.text);
}

void Renderer::draw(Pokemon& pokemon, Side side)
{
	if (side == Side::front) {
		draw(pokemon.front, 6.0);
	}
	else {
		draw(pokemon.back, 6.0);
	}
	//TODO UI hp bar
}

void Renderer::draw(TextArea& textArea)
{
	// Background
	textArea.sprite.setScale(scale, scale);
	textArea.sprite.setPosition(textArea.position);
	window.draw(textArea.sprite);
	// Text
	textArea.text.setScale(scale, scale);
	textArea.text.setPosition(textArea.textPos);
	window.draw(textArea.text);
}

void Renderer::setScale()
{
	scale = window.getSize().x / 1280.0f;
}

sf::RenderWindow& Renderer::getWindow() {
	return window;
}