#pragma once
#include <pugixml.hpp>
#include <vector>
#include "PokemonTypes.h"
class Move
{
private:
	std::string name;
	PokemonType type;
	float power;
	// TODO if time : conditions (sleep, paralyze etc)
public:
	Move();
	Move(std::string name_, PokemonType type_, float power_);
	void save(pugi::xml_node& node);
	std::vector<std::string> data();

	friend Move load_move(pugi::xml_node& node);
};

Move load_move(pugi::xml_node& node);
