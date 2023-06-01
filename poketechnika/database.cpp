#include "database.h"
#include "GameManager.h"
#include "Exception.h"

#include <iostream>
#include <fstream>
#include <string>

pugi::xml_document load_xml_file(const char* filename) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename);
	if (result) {
		return doc;
	}
	throw Exception(result.description());
}

const std::string DB_PATH = "./../db.txt";

GameManager load() {
	std::ifstream dbFile{ DB_PATH };
	GameManager state;
	dbFile >> state;
	return state;
}

void save(GameManager& state) {
	std::ofstream dbFile{ DB_PATH };
	dbFile << state;
}
