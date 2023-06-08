#include "Drawable.h"
#include "Exception.h"

Drawable::Drawable(const std::string& texture_file, sf::Vector2f pos) 
	: position{ pos }, texture {}, sprite{}, file{ texture_file } 
{
	if (texture.loadFromFile(file)) {
		sprite.setTexture(texture);
	}
	else {
		throw Exception{ "Unable to load texture from " + file };
	}
}

Drawable::Drawable(const Drawable& other) 
	: position{ other.position }, texture {other.texture}, sprite{}, file{ other.file } 
{
	sprite.setTexture(texture);
}

Drawable& Drawable::operator= (const Drawable& other) {
	position = other.position;
	file = other.file;
	texture = other.texture;
	sprite.setTexture(texture);
	return *this;
}
