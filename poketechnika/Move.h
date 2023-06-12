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

	// Returns move's name, type & power as string
	std::vector<std::string> data();
	
	// Returns move type
	PokemonType getType();
	// Returns move name
	std::string getName();
	// returns move power
	float getPower();
	// Checks if given attack is effective, super effective or not effective against enemy pokemon
	float getModifier(PokemonType attack, PokemonType pokemon_first, PokemonType pokemon_second);

	friend Move load_move(pugi::xml_node& node);
};

// loads move from given xml file fragment
Move load_move(pugi::xml_node& node);
