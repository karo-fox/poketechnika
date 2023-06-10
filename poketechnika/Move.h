#pragma once
#include <iostream>
#include <pugixml.hpp>
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
};
public:
	Move(std::string name_, PokemonType type_, float power_);
	void save(pugi::xml_node& node);

	friend Move load_move(pugi::xml_node& node);
};

Move load_move(pugi::xml_node& node);
