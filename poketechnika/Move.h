#pragma once
#include <iostream>
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