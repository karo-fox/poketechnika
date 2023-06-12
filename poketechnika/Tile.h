#pragma once
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>
#include "Drawable.h"

enum class tileTypes {
	GRASS, PAVEMENT, STREET, PATH, BUILDING, ROOF, BUSH, BOSS
};

class Tile : public Drawable
{
private:
	bool passable;
	static int tileSize;
	tileTypes type;
	sf::Vector2f scale;
public:
	Tile(tileTypes type_, sf::Vector2f pos, bool passable_, sf::Vector2f s = sf::Vector2f{ 2, 2 });
	Tile(const Tile& other);
	// Checks if tile is passable
	bool isPassable() const;
	// Checks if tile is of given type
	bool isType(tileTypes type_) const;

	Tile& operator= (const Tile& other);

	friend Tile tile_from_xml(pugi::xml_node& tile_node, int x, int y);
	friend void tile_to_xml(Tile& tile, pugi::xml_node& parent, bool save_position);
};

// Loads the tile from xml file
Tile tile_from_xml(pugi::xml_node& tile_node, int x, int y);
// Saves the tile to xml file
void tile_to_xml(Tile& tile, pugi::xml_node& parent, bool save_position = false);
