#include "database.h"
#include "State.h"

#include <iostream>
#include <fstream>
#include <string>

const std::string DB_PATH = "./../db.txt";

State load() {
	std::ifstream dbFile { DB_PATH };
	State state;
	dbFile >> state;
	return state;
}

void save(State& state) {
	std::ofstream dbFile{ DB_PATH };
	dbFile << state;
}