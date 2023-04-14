#include "GameManager.h"
#include "database.h"
#include <iostream>

GameManager::GameManager() : player( Position{ 0, 0 }) {
	map = nullptr;
}

GameManager::~GameManager() {
	save(*this);
}

void GameManager::loadMap() {
	map = new Map();
	map->id = 0;
	map->name = "DEVZONE";
	std::vector<std::vector<Tile*>> temp2d;
	for (int i = 0; i < 20; i++)
	{
		std::vector<Tile*> temp;
		for (int j = 0; j < 20; j++)
		{
			temp.push_back(new Tile(tileTypes::GRASS, sf::Vector2i(i*64, j*64), true));
		}
		temp2d.push_back(temp);
	}
	map->layers.push_back(temp2d);
}

void GameManager::unloadMap()
{
	if (map != nullptr)
	{
		for (int i = 0; i < map->layers.size(); i++)
		{
			for (int j = 0; j < map->layers[i].size(); j++)
			{
				for (int k = 0; k < map->layers[i][j].size(); k++)
				{
					delete map->layers[i][j][k];
					map->layers[i][j].erase(map->layers[i][j].begin() + k);
				}
				map->layers[i][j].clear();
			}
			map->layers[i].clear();
		}
		delete map;
		map->layers.clear();
	}
}

std::ifstream& operator>> (std::ifstream& in, GameManager& state) {
	in >> state.player.x;
	in >> state.player.y;
	return in;
};


std::ofstream& operator<< (std::ofstream& out, GameManager& state) {
	out << state.player.x << ' ';
	out << state.player.y << ' ';
	return out;
}