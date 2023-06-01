#include "database.h"
#include "GameManager.h"

#include <iostream>
#include <fstream>
#include <string>

pugi::xml_document load_xml_file(const std::string& filename) {
	pugi::xml_document doc{};
	pugi::xml_parse_result result = doc.load_file(filename.c_str());
	if (result.status == pugi::status_ok) {
		return doc;
	}
	throw result.description();
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
