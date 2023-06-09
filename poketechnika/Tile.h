#pragma once
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>
#include "Drawable.h"

enum class tileTypes {
	GRASS, PAVEMENT, STREET, PATH, BUILDING, ROOF, BUSH
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
	bool isPassable() const;

	Tile& operator= (const Tile& other);

	friend Tile tile_from_xml(pugi::xml_node& tile_node, int x, int y);
	friend void tile_to_xml(Tile& tile, pugi::xml_node& parent, bool save_position);
};

Tile tile_from_xml(pugi::xml_node& tile_node, int x, int y);
void tile_to_xml(Tile& tile, pugi::xml_node& parent, bool save_position = false);
