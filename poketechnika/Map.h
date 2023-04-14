#pragma once
#include <string>
#include <vector>
#include "Tile.h"
class Map
{
public:
	int id;
	std::string name;
	std::vector<std::vector<std::vector<Tile*>>> layers;
};