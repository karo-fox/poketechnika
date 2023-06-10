#include <iostream>
#include "Map.h"
#include "Exception.h"

Map::Map(int id_, std::string name_, LayerArray layers_) : 
	id{ id_ }, name{ name_ }, layers{ layers_ } {}

Map::Map(const Map& other) : id{ other.id }, name{ other.name }, layers{ LayerArray{} } {
	for (auto& vec1 : other.layers) {
		std::vector<std::vector<Tile>> y_axis{};
		for (auto& vec2 : vec1) {
			std::vector<Tile> x_axis{};
			for (auto& other_tile : vec2) {
				Tile tile{ other_tile };
				x_axis.push_back(tile);
			}
			y_axis.push_back(x_axis);
		}
		layers.push_back(y_axis);
	}
}

Map& Map::operator=(const Map& other)
{
	id = other.id;
	name = other.name;
	layers = LayerArray{};

	for (auto& vec1 : other.layers) {
		std::vector<std::vector<Tile>> y_axis{};
		for (auto& vec2 : vec1) {
			std::vector<Tile> x_axis{};
			for (auto& other_tile : vec2) {
				Tile tile{ other_tile };
				x_axis.push_back(tile);
			}
			y_axis.push_back(x_axis);
		}
		layers.push_back(y_axis);
	}

	return *this;
}

Map map_from_xml(pugi::xml_node& map_node)
{
	int id = map_node.child("id").first_child().text().as_int();
	std::string name = map_node.child("name").first_child().text().as_string();
	LayerArray layers{};
	pugi::xml_node layers_node = map_node.child("layers");
	for (auto& y_axis_nodes : layers_node.children("y_axis")) {
		int y_idx{};
		std::vector<std::vector<Tile>> y_axis{};
		for (auto& x_axis_nodes : y_axis_nodes.children("x_axis")) {
			int x_idx{};
			std::vector<Tile> x_axis{};
			for (auto& tile_node : x_axis_nodes) {
				try {
					Tile tile = tile_from_xml(tile_node, x_idx, y_idx);
					x_axis.push_back(tile);
					x_idx++;
				} catch (const Exception& e) {
					std::cout << e.what() << '\n';
				}				
			}
			y_axis.push_back(x_axis);
			y_idx++;
		}
		layers.push_back(y_axis);
	}
	Map map{ id, name, layers };
	return map;
}

void map_to_xml(Map& map, pugi::xml_node& map_node)
{
	pugi::xml_node id = map_node.append_child("id");
	id.first_child().text().set(map.id);

	pugi::xml_node name = map_node.append_child("name");
	name.first_child().text().set(map.name.c_str());

	pugi::xml_node layers = map_node.append_child("layers");
	int layer_idx{};
	for (auto& y_axis_vec : map.layers) {
		pugi::xml_node y_axis_node = layers.append_child("y_axis");
		for (auto& x_axis_vec : y_axis_vec) {
			pugi::xml_node x_axis_node = y_axis_node.append_child("x_axis");
			for (auto& tile : x_axis_vec) {
				tile_to_xml(tile, x_axis_node, layer_idx != 0);
			}
		}
		layer_idx++;
	}
}

sf::Vector2f Map::getMapSize()
{
	return sf::Vector2f(layers[0].size() * 64, layers[0][0].size() * 64);
}

bool Map::isPassable(sf::Vector2f pos) const
{
	if (pos.x < 0 || pos.y < 0) return false;
	for (int i = 0; i < layers.at(0).size(); i++)
	{
		if ((i + 1) * 64 >= pos.y)
		{
			for (int j = 0; j < layers[0][i].size(); j++)
			{
				if ((j + 1) * 64 >= pos.x)
				{
					return layers[0][i][j].isPassable();
				}
			}
		}
	}
	return false;
}

bool Map::isBush(sf::Vector2f pos) const
{
	sf::Vector2f chk = sf::Vector2f(((int)pos.x - (int)pos.x % 64), ((int)pos.y - (int)pos.y % 64));
	for (int i = 0; i < layers.at(1).size(); i++)
	{
		for (int j = 0; j < layers[1][i].size(); j++)
		{
			if (chk.x == layers[1][i][j].position.x && chk.y == layers[1][i][j].position.y)
			{
				return layers[1][i][j].isType(tileTypes::BUSH);
			}
		}
	}
	return false;
}