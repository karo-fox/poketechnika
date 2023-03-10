#pragma once

#include <fstream>

struct Position {
	int x;
	int y;
};

class GameManager
{
private:
	Position player;
public:
	GameManager();
	~GameManager();

	friend std::ifstream& operator>> (std::ifstream& in, GameManager& state);
	friend std::ofstream& operator<< (std::ofstream& out, GameManager& state);
};
