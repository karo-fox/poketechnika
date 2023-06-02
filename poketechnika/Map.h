#pragma once
#include <string>
#include <vector>
#include "Tile.h"
#include <pugixml.hpp>

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
	
	friend Map map_from_xml(pugi::xml_node& map_node);
	friend void map_to_xml(Map& map, pugi::xml_node& parent);
};

Map map_from_xml(pugi::xml_node& map_node);
void map_to_xml(Map& map, pugi::xml_node& parent);
