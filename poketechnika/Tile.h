#pragma once
#include "GameObject.h"

enum class tileTypes {
	GRASS, DIRT, FLOOR
};

class Tile : public GameObject
{
private:
	sf::Texture tileTexture;
	sf::Sprite tileSprite;
	bool passable;
	static int tileSize;
public:
	Tile(tileTypes type, sf::Vector2i pos, bool passable_);
	~Tile();
	sf::Sprite getSprite();
};