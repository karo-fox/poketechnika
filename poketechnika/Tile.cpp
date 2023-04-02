#include "Tile.h"
#include <iostream>

Tile::Tile(tileTypes type, sf::Vector2i pos, bool passable_) {
	this->position = pos;
	this->passable = passable_;
	switch (type)
	{
	case tileTypes::GRASS:
		tileTexture.loadFromFile("assets/textures/grass.png");
	}
	tileSprite.setTexture(tileTexture);
}

Tile::~Tile() {
}

sf::Sprite Tile::getSprite()
{
	return tileSprite;
}