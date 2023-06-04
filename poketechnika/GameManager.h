#pragma once

#include <fstream>
#include "Map.h"
#include "Player.h"

enum class MapId {
	TEST, TEST1
};

class GameManager
{
public:
	Map map;
	Player player;
	GameManager();
	~GameManager();
	Map loadMap(MapId map_id);
	void unloadMap();
	void start();
};
