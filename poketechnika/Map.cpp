#include "Map.h"
#include "Exception.h"
#include <vector>
#include <iostream>

Map::Map(int id_, std::string name_, LayerArray layers_) : 
	id{ id_ }, name{ name_ }, layers{ layers_ } {}

bool Map::isPassable(sf::Vector2f pos)
{
	if (pos.x < 0 || pos.y < 0) return false;
	for (int i = 0; i < layers[0].size(); i++)
	{
		if ((i+1) * 64 >= pos.x)
		{
			for (int j = 0; j < layers[0][i].size(); j++)
			{
				if ((j+1) * 64 >= pos.y)
				{
					return layers[0][i][j].isPassable();
				}
			}
		}
	}
	return false;
}

Map::Map(const Map& other) : id{ other.id }, name{ other.name }, layers{ LayerArray{} } {
	for (auto& vec1 : other.layers) {
		std::vector<std::vector<Tile>> x_axis{};
		for (auto& vec2 : vec1) {
			std::vector<Tile> y_axis{};
			for (auto& other_tile : vec2) {
				Tile tile{ other_tile };
				y_axis.push_back(tile);
			}
			x_axis.push_back(y_axis);
		}
		layers.push_back(x_axis);
	}
}

Map& Map::operator=(const Map& other)
{
	id = other.id;
	name = other.name;
	layers = LayerArray{};

	for (auto& vec1 : other.layers) {
		std::vector<std::vector<Tile>> x_axis{};
		for (auto& vec2 : vec1) {
			std::vector<Tile> y_axis{};
			for (auto& other_tile : vec2) {
				Tile tile{ other_tile };
				y_axis.push_back(tile);
			}
			x_axis.push_back(y_axis);
		}
		layers.push_back(x_axis);
	}

	return *this;
}

Map map_from_xml(pugi::xml_node& map_node)
{
	int id = std::stoi(map_node.child("id").child_value());
	std::string name = map_node.child("name").child_value();
	LayerArray layers{};
	pugi::xml_node layers_node = map_node.child("layers");
	for (auto& x_axis_nodes : layers_node.children("x_axis")) {
		std::vector<std::vector<Tile>> x_axis{};
		for (auto& y_axis_nodes : x_axis_nodes.children("y_axis")) {
			std::vector<Tile> y_axis{};
			for (auto& tile_node : y_axis_nodes) {
				try {
					Tile tile = tile_from_xml(tile_node);
					y_axis.push_back(tile);
				} catch (const Exception& e) {
					std::cout << e.what() << '\n';
				}				
			}
			x_axis.push_back(y_axis);
		}
		layers.push_back(x_axis);
	}
	Map map{ id, name, layers };
	return map;
}

void map_to_xml(Map& map, pugi::xml_node& parent)
{
	pugi::xml_node map_node = parent.append_child("map");

	pugi::xml_node id = map_node.append_child("id");
	id.append_child(pugi::node_pcdata).set_value(std::to_string(map.id).c_str());

	pugi::xml_node name = map_node.append_child("name");
	name.append_child(pugi::node_pcdata).set_value(map.name.c_str());

	pugi::xml_node layers = map_node.append_child("layers");
	for (auto& x_axis_vec : map.layers) {
		pugi::xml_node x_axis_node = layers.append_child("x_axis");
		for (auto& y_axis_vec : x_axis_vec) {
			pugi::xml_node y_axis_node = x_axis_node.append_child("y_axis");
			for (auto& tile : y_axis_vec) {
				tile_to_xml(tile, y_axis_node);
			}
		}
	}
}