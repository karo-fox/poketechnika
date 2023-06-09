#include "Drawable.h"
#include "Exception.h"

Drawable::Drawable(const std::string& texture_file, const sf::Vector2f& pos) 
	: position{ pos }, texture {}, sprite{}, file{ texture_file }, scalable(false)
{
	if (texture.loadFromFile(file)) {
		sprite.setTexture(texture);
	}
	else {
		throw Exception{ "Unable to load texture from " + file };
	}
}

Drawable::Drawable(const std::string& texture_file, const sf::Vector2f& pos, bool scal)
	: position{ pos }, texture{}, sprite{}, file{ texture_file }, scalable(scal)
{
	if (texture.loadFromFile(file)) {
		sprite.setTexture(texture);
	}
	else {
		throw Exception{ "Unable to load texture from " + file };
	}
}

Drawable::Drawable(const Drawable& other) 
	: position{ other.position }, texture {other.texture}, sprite{}, file{ other.file }, scalable(other.scalable)
{
	sprite.setTexture(texture);
}

Drawable& Drawable::operator= (const Drawable& other) {
	position = other.position;
	file = other.file;
	texture = other.texture;
	scalable = other.scalable;
	sprite.setTexture(texture);
	return *this;
}

bool Drawable::isScalable()
{
	return scalable;
}