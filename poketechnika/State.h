#pragma once

#include <fstream>

struct Position {
	int x;
	int y;
};

class State
{
private:
	Position player;
public:
	State();
	~State();

	friend std::ifstream& operator>> (std::ifstream& in, State& state);
	friend std::ofstream& operator<< (std::ofstream& out, State& state);
};
