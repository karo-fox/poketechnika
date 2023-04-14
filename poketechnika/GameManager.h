#pragma once

#include <fstream>
#include "Map.h"

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
	void loadMap();
	void unloadMap();

	friend std::ifstream& operator>> (std::ifstream& in, GameManager& state);
	friend std::ofstream& operator<< (std::ofstream& out, GameManager& state);
};
