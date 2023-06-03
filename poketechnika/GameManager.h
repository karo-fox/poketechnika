#pragma once

#include <fstream>
#include "Map.h"

enum class MapId {
	TEST, TEST1
};

class GameManager
{
public:
	Map map;
	GameManager();
	~GameManager();
	Map loadMap(MapId map_id);
	void unloadMap();
};
