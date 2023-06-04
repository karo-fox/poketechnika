#include "Tile.h"
#include "Exception.h"
#include <iostream>
#include <pugixml.hpp>
#include <map>
#include <string>

const std::string TEXTURES_DIR = "assets/textures";
const sf::Vector2f SCALE{ 2, 2 };

std::map<tileTypes, std::string> textures{
	{tileTypes::GRASS, std::string{TEXTURES_DIR + "/grass_tile.png"}},
	{tileTypes::PAVEMENT, std::string{TEXTURES_DIR + "/pavement_tile.png"}},
	{tileTypes::STREET, std::string{TEXTURES_DIR + "/street_tile.png"}},
	{tileTypes::PATH, std::string{TEXTURES_DIR + "/path_tile.png"}},
	{tileTypes::BUILDING, std::string{TEXTURES_DIR + "/building_tile.png"}},
};

Tile::Tile(const Tile& other) : tileTexture{ sf::Texture{} }, tileSprite{ sf::Sprite{} }
{
	position = other.position;
	passable = other.passable;
	type = other.type;

	if (tileTexture.loadFromFile(textures.at(type))) {
		tileSprite.setTexture(tileTexture);
		tileSprite.setScale(SCALE);
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
		tileSprite.setScale(SCALE);
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
		tileSprite.setScale(SCALE);
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

Tile tile_from_xml(pugi::xml_node& tile_node, int x, int y)
{
	if (tile_node.child("position").hash_value()) {
		x = std::stoi(tile_node.child("position").child("x").child_value());
		y = std::stoi(tile_node.child("position").child("y").child_value());
	}
	x *= 64;
	y *= 64;

	tileTypes type = static_cast<tileTypes>(std::stoi(tile_node.child("type").child_value()));

	bool passable{};
	switch (type) {
	case tileTypes::BUILDING:
		passable = false;
		break;
	case tileTypes::GRASS:
	case tileTypes::PATH:
	case tileTypes::PAVEMENT:
	case tileTypes::STREET:
	default:
		passable = true;
		break;
	}
	
	Tile tile{ type, sf::Vector2f{static_cast<float>(x), static_cast<float>(y)}, passable};
	return tile;
}

void tile_to_xml(Tile& tile, pugi::xml_node& parent, bool save_position)
{
	pugi::xml_node tile_node = parent.append_child("tile");

	if (save_position) {
		pugi::xml_node position = tile_node.append_child("position");
		pugi::xml_node x = position.append_child("x");
		x.append_child(pugi::node_pcdata).set_value(std::to_string(tile.position.x).c_str());
		pugi::xml_node y = position.append_child("y");
		y.append_child(pugi::node_pcdata).set_value(std::to_string(tile.position.y).c_str());
	}

	pugi::xml_node type = tile_node.append_child("type");
	type.append_child(pugi::node_pcdata).set_value(std::to_string(static_cast<int>(tile.type)).c_str());
}
