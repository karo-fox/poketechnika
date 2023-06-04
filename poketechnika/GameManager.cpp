#include "GameManager.h"
#include "database.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <map>
#include <pugixml.hpp>

std::map<MapId, const char*> map_files{
	{MapId::FACULTY_ENTRANCE, "data/faculty_entrance.xml"},
};

GameManager::GameManager() : map_type{ MapId::FACULTY_ENTRANCE } {}

GameManager::~GameManager() {
	player.remove();
}

void GameManager::loadMap() {
	try {
		pugi::xml_document map_file = load_xml_file(map_files.at(map_type));
		pugi::xml_node map_node = map_file.child("map");
		map =  map_from_xml(map_node);
	}
	catch (const Exception& e) {
		std::cout << e.what() << '\n';
	}
}

void GameManager::unloadMap()
{
	map.layers.clear();	
}

void GameManager::start()
{
	loadMap();
	player.setMapPtr(&map);
	player.add();
}

void GameManager::changeMap(MapId new_map)
{
	map_type = new_map;
}
