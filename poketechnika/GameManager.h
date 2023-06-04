#pragma once

#include <fstream>
#include "Map.h"
#include "Player.h"

enum class MapId {
	FACULTY_ENTRANCE, FACULTY_INTERIOR, PARK
};

class GameManager
{
public:
	MapId map_type;
	Map map;
	Player player;
	GameManager();
	~GameManager();
	void loadMap();
	void unloadMap();
	void start();
	void changeMap(MapId new_map);
};
