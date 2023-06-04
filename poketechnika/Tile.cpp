#include "Tile.h"
#include "Exception.h"
#include <iostream>
#include <pugixml.hpp>
#include <map>
#include <string>

std::map<tileTypes, std::string> textures{
	{tileTypes::GRASS, std::string{"assets/textures/grass.png"}},
	{tileTypes::DIRT, std::string{"assets/textures/dirt.png"}},
	{tileTypes::FLOOR, std::string{"assets/textures/floor.png"}},
	{tileTypes::WALL, std::string{"assets/textures/wall.png"}},
};

Tile::Tile(const Tile& other) : tileTexture{ sf::Texture{} }, tileSprite{ sf::Sprite{} }
{
	position = other.position;
	passable = other.passable;
	type = other.type;

	if (tileTexture.loadFromFile(textures.at(type))) {
		tileSprite.setTexture(tileTexture);
	}
	else {
		throw Exception("Unable to load a texture from " + textures.at(type));
	}
}

Tile::Tile(tileTypes type_, sf::Vector2f pos, bool passable_) : tileTexture{ sf::Texture{} }, tileSprite { sf::Sprite{} } {
	position = pos;
	passable = passable_;
	type = type_;

	if (tileTexture.loadFromFile(textures.at(type))) {
		tileSprite.setTexture(tileTexture);
	}
	else {
		throw Exception("Unable to load a texture from " + textures.at(type));
	}
}

Tile::~Tile() {}

bool Tile::isPassable()
{
	return passable;
}

Tile& Tile::operator=(const Tile& other)
{
	position = other.position;
	passable = other.passable;
	type = other.type;

	if (tileTexture.loadFromFile(textures.at(type))) {
		tileSprite.setTexture(tileTexture);
	}
	else {
		throw Exception("Unable to load a texture from " + textures.at(type));
	}

	return *this;
}

sf::Sprite Tile::getSprite()
{
	return tileSprite;
}

Tile tile_from_xml(pugi::xml_node& tile_node)
{
	float x = std::stoi(tile_node.child("position").child("x").child_value()) * 64;
	float y = std::stoi(tile_node.child("position").child("y").child_value()) * 64;
	bool passable = std::stoi(tile_node.child("passable").child_value());
	tileTypes type = static_cast<tileTypes>(std::stoi(tile_node.child("type").child_value()));
	Tile tile{ type, sf::Vector2f{x ,y}, passable };
	return tile;
}

void tile_to_xml(Tile& tile, pugi::xml_node& parent)
{
	pugi::xml_node tile_node = parent.append_child("tile");

	pugi::xml_node position = tile_node.append_child("position");
	pugi::xml_node x = position.append_child("x");
	x.append_child(pugi::node_pcdata).set_value(std::to_string(tile.position.x).c_str());
	pugi::xml_node y = position.append_child("y");
	y.append_child(pugi::node_pcdata).set_value(std::to_string(tile.position.y).c_str());

	pugi::xml_node passable = tile_node.append_child("passable");
	passable.append_child(pugi::node_pcdata).set_value(std::to_string(tile.passable).c_str());

	pugi::xml_node type = tile_node.append_child("type");
	type.append_child(pugi::node_pcdata).set_value(std::to_string(static_cast<int>(tile.type)).c_str());
}
