#pragma once
#include <string>
#include <vector>
#include <pugixml.hpp>
#include "Tile.h"

using LayerArray = std::vector<std::vector<std::vector<Tile>>>;

class Map
{
public:
	int id;
	std::string name;
	LayerArray layers;

	Map(int id_ = 0, std::string name_ = "", LayerArray layers_ = {});
	Map(const Map& other);
	Map& operator= (const Map& other);

	// Checks if Tile on given position is passable
	bool isPassable(sf::Vector2f pos) const;
	// Checks the type of Tile on given position
	bool isTileType(sf::Vector2f pos, tileTypes type) const;
	// Returns map's size
	sf::Vector2f getMapSize();
	
	friend Map map_from_xml(pugi::xml_node& map_node);
	friend void map_to_xml(Map& map, pugi::xml_node& parent);
};

// Loads map from xml file
Map map_from_xml(pugi::xml_node& map_node);
// Saves map to xml file
void map_to_xml(Map& map, pugi::xml_node& parent);
