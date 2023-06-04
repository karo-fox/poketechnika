#pragma once
#include "GameObject.h"
#include <pugixml.hpp>

enum class tileTypes {
	GRASS, DIRT, FLOOR, WALL
};

class Tile : public GameObject
{
private:
	sf::Texture tileTexture;
	sf::Sprite tileSprite;
	bool passable;
	static int tileSize;
	tileTypes type;
public:
	Tile(tileTypes type_, sf::Vector2f pos, bool passable_);
	Tile(const Tile& other);
	~Tile();
	sf::Sprite getSprite();
	bool isPassable();
	Tile& operator= (const Tile& other);
	friend Tile tile_from_xml(pugi::xml_node& tile_node);
	friend void tile_to_xml(Tile& tile, pugi::xml_node& parent);
};

Tile tile_from_xml(pugi::xml_node& tile_node);
void tile_to_xml(Tile& tile, pugi::xml_node& parent);
