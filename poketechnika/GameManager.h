#pragma once

#include <fstream>
#include "Map.h"

enum class MapId {
	TEST
};

struct Position {
	int x;
	int y;
};

class GameManager
{
private:
	Position player;
public:
	Map* map;
	GameManager();
	~GameManager();
	void loadMap(MapId map_id);
	void unloadMap();

	friend std::ifstream& operator>> (std::ifstream& in, GameManager& state);
	friend std::ofstream& operator<< (std::ofstream& out, GameManager& state);
};
