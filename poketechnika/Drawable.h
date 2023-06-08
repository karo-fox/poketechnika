#pragma once
#include <string>
#include <SFML/Graphics.hpp>

// Every Drawable object can be rendered by Renderer
class Drawable {
protected:
	sf::Texture texture;
	std::string file;
public:
	sf::Sprite sprite;
	sf::Vector2f position;

	Drawable(const std::string& texture_file, sf::Vector2f pos);
	Drawable(const Drawable& other);
	Drawable& operator= (const Drawable& other);
};
