#include "Tile.h"

const std::string TEXTURES_DIR = "assets/textures";

std::map<tileTypes, std::string> textures{
	{tileTypes::GRASS, std::string{TEXTURES_DIR + "/grass_tile.png"}},
	{tileTypes::PAVEMENT, std::string{TEXTURES_DIR +  "/pavement_tile.png"}},
	{tileTypes::STREET, std::string{TEXTURES_DIR + "/street_tile.png"}},
	{tileTypes::PATH, std::string{TEXTURES_DIR + "/path_tile.png"}},
	{tileTypes::BUILDING, std::string{TEXTURES_DIR + "/building_tile.png"}},
	{tileTypes::ROOF, std::string{TEXTURES_DIR + "/roof_tile.png"}},
	{tileTypes::BUSH, std::string{TEXTURES_DIR + "/bush-1.png"}},
};

Tile::Tile(tileTypes type_, sf::Vector2f pos, bool passable_, sf::Vector2f s)
	: Drawable{ textures.at(type_), pos }, scale{ s }
{
	position = pos;
	passable = passable_;
	type = type_;

	sprite.setScale(scale);
}

Tile::Tile(const Tile& other) : Drawable{ other }
{
	position = other.position;
	passable = other.passable;
	type = other.type;
	scale = other.scale;

	sprite.setScale(scale);
}

Tile& Tile::operator=(const Tile& other)
{
	position = other.position;
	passable = other.passable;
	type = other.type;
	scale = other.scale;

	Drawable::operator=(other);

	return *this;
}

Tile tile_from_xml(pugi::xml_node& tile_node, int x, int y)
{
	if (tile_node.child("position").hash_value()) {
		x = std::stoi(tile_node.child("position").child("x").child_value());
		y = std::stoi(tile_node.child("position").child("y").child_value());
	}

	tileTypes type = static_cast<tileTypes>(std::stoi(tile_node.child("type").child_value()));

	bool passable{};
	switch (type) {
	case tileTypes::BUILDING:
	case tileTypes::ROOF:
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

	int scale = 2;
	if (tile_node.child("scale").hash_value()) {
		scale = std::stoi(tile_node.child("scale").child_value());
	}

	Tile tile{ 
		type, sf::Vector2f{static_cast<float>(x * 64) ,static_cast<float>(y * 64)}, 
		passable, sf::Vector2f{static_cast<float>(scale), static_cast<float>(scale)}
	};
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

	if (tile.scale.x != 2 && tile.scale.y != 2) {
		pugi::xml_node scale = tile_node.append_child("scale");
		scale.append_child(pugi::node_pcdata).set_value(std::to_string(tile.scale.x).c_str());
	}
}

bool Tile::isPassable() const
{
	return passable;
}

bool Tile::isType(tileTypes type_) const
{
	if (type_ == type) return true;
	else return false;
}