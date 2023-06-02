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
	map = loadMap(MapId::TEST);
}

GameManager::~GameManager() {
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

	//map->id = 0;
	//map->name = "DEVZONE";
	//std::vector<std::vector<Tile*>> temp2d;
	//for (int i = 0; i < 20; i++)
	//{
	//	std::vector<Tile*> temp;
	//	for (int j = 0; j < 20; j++)
	//	{
	//		temp.push_back(new Tile(tileTypes::GRASS, sf::Vector2i(i*64, j*64), true));
	//	}
	//	temp2d.push_back(temp);
	//}
	//map->layers.push_back(temp2d);
}

void GameManager::unloadMap()
{
	//for (int i = 0; i < map.layers.size(); i++)
	//{
	//	for (int j = 0; j < map.layers[i].size(); j++)
	//	{
	//		for (int k = 0; k < map.layers[i][j].size(); k++)
	//		{
	//			//delete map.layers[i][j][k];
	//			map.layers[i][j].erase(map.layers[i][j].begin() + k);
	//		}
	//		map.layers[i][j].clear();
	//	}
	//	map.layers[i].clear();
	//}
	map.layers.clear();	
}
