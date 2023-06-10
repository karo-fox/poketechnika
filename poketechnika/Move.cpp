#include "Move.h"

Move::Move() : name("ERROR"), type(PokemonType::NORMAL), power(1.0f) {}

Move::Move(std::string name_, PokemonType type_, float power_)
	: name{ name_ }, type{ type_ }, power{ power_ } {}

Move load_move(pugi::xml_node& node) {
	std::string name = node.child("name").first_child().text().as_string();
	PokemonType type = static_cast<PokemonType>(node.child("type").first_child().text().as_int());
	float power = node.child("power").first_child().text().as_float();
	Move move{ name, type, power };
	return move;
}

void Move::save(pugi::xml_node& node) {
	node.child("name").first_child().text().set(name.c_str());
	node.child("type").first_child().text().set(static_cast<int>(type));
	node.child("power").first_child().text().set(power);
}
