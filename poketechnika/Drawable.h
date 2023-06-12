#pragma once
#include <string>
#include <SFML/Graphics.hpp>

// Every Drawable object can be rendered by Renderer
class Drawable {
protected:
	sf::Texture texture;
	bool scalable;
public:
	std::string file;
	sf::Sprite sprite;
	sf::Vector2f position;

	Drawable(const std::string& texture_file, const sf::Vector2f& pos);
	Drawable(const std::string& texture_file, sf::IntRect rect, const sf::Vector2f& pos);
	Drawable(const std::string& texture_file, const sf::Vector2f& pos, bool scal);
	Drawable(const Drawable& other);
	Drawable& operator= (const Drawable& other);

	// Checks if Drawable is scalable
	bool isScalable();
};
