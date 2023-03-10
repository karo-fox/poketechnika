#include "database.h"
#include "GameManager.h"

#include <iostream>
#include <fstream>
#include <string>

const std::string DB_PATH = "./../db.txt";

GameManager load() {
	std::ifstream dbFile { DB_PATH };
	GameManager state;
	dbFile >> state;
	return state;
}

void save(GameManager& state) {
	std::ofstream dbFile{ DB_PATH };
	dbFile << state;
}