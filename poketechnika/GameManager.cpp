#include "GameManager.h"
#include "database.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <map>
#include <pugixml.hpp>

std::map<MapId, const char*> map_files{
	{MapId::TEST, "data/test_map.xml"},
	{MapId::TEST1, "data/test_map1.xml"},
};

GameManager::GameManager() {
	
}

GameManager::~GameManager() {
	player.remove();
}

Map GameManager::loadMap(MapId map_id) {
	try {
		pugi::xml_document map_file = load_xml_file(map_files.at(map_id));
		pugi::xml_node map_node = map_file.child("map");
		Map map =  map_from_xml(map_node);
		return map;
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
	map = loadMap(MapId::TEST);
	player.setMapPtr(&map);
	player.add();
}