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

void Renderer::draw(Button& button, float scale_rate) {
	if (button.isScalable()) {
		button.sprite.setScale(scale * scale_rate, scale * scale_rate);
		button.sprite.setPosition(button.position * scale);
	}
	else {
		button.sprite.setPosition(button.position);
	}	
	window.draw(button.sprite);
	if (button.isScalable()) {
		button.text.setScale(scale, scale);
		button.text.setPosition(
			button.position.x * scale + 3 * scale_rate, 
			button.position.y * scale + 3 * scale_rate
		);
	}
	else {
		button.text.setPosition(button.position.x + 3, button.position.y + 3);
	}
	window.draw(button.text);
}

void Renderer::draw(ImageButton& button, float scale_rate) {
	if (button.isScalable()) {
		button.sprite.setScale(scale * scale_rate, scale * scale_rate);
		button.sprite.setPosition(button.position * scale);
		button.image.sprite.setScale(scale, scale);
		button.image.sprite.setPosition(button.position * scale);
	}
	else {
		button.sprite.setPosition(button.position);
		button.image.sprite.setPosition(button.position);
	}
	window.draw(button.sprite);
	window.draw(button.image.sprite);
}

void Renderer::draw(Text3Button& button, float scale_rate)
{
	if (button.isScalable()) {
		button.sprite.setScale(scale * scale_rate, scale * scale_rate);
		button.sprite.setPosition(button.position * scale);
		button.text.setScale(scale, scale);
		button.text.setPosition(
			button.position.x * scale + 3 * scale,
			button.position.y * scale + 3 * scale
		);
		button.text2.setScale(scale, scale);
		button.text2.setPosition(
			button.position.x * scale + 3 * scale,
			button.position.y * scale + (3 + 24) * scale
		);
		button.text3.setScale(scale, scale);
		button.text3.setPosition(
			button.position.x * scale + 3 * scale,
			button.position.y * scale + (3 + 48) * scale
		);
	}
	else {
		button.sprite.setPosition(button.position);
		button.text.setPosition(button.position.x + 3, button.position.y + 3);
		button.text2.setPosition(button.position.x + 3, button.position.y + 3 + 24);
		button.text3.setPosition(button.position.x + 3, button.position.y + 3 + 48);
	}
	window.draw(button.sprite);
	window.draw(button.text);
	window.draw(button.text2);
	window.draw(button.text3);
}

void Renderer::draw(Pokemon& pokemon, Side side)
{
	if (side == Side::front) {
		draw(pokemon.front, 6.0);
		Bar hp_bar{ 
			pokemon.getMaxHp(), pokemon.getHp(), 
			sf::Vector2f{
				pokemon.front.position.x,
				pokemon.front.position.y + 375
			}
		};
		draw(hp_bar);
	}
	else {
		draw(pokemon.back, 6.0);
		Bar hp_bar{ 
			pokemon.getMaxHp(), pokemon.getHp(), 
			sf::Vector2f{
				pokemon.back.position.x, 
				pokemon.back.position.y + 100
		}
		};
		draw(hp_bar);
	}
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

void Renderer::draw(Bar& bar, float scale_rate) {
	bar.sprite.setScale(scale, scale);
	bar.sprite.setPosition(bar.position * scale);
	window.draw(bar.sprite);

	bar.progress.sprite.setScale(scale, scale);
	bar.progress.sprite.setPosition(bar.position * scale);
	window.draw(bar.progress.sprite);

	bar.text.setScale(scale, scale);
	bar.text.setPosition(
		(bar.position.x + bar.sprite.getTextureRect().width + 10) * scale,
		bar.position.y * scale
	);
	window.draw(bar.text);
}

void Renderer::setScale()
{
	scale = window.getSize().x / 1280.0f;
}

sf::RenderWindow& Renderer::getWindow() {
	return window;
}