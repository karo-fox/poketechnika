#pragma once
#include <iostream>
#include "PokemonTypes.h"
class Move
{
private:
	std::string name;
	PokemonType type;
	float dmg;
	// TODO if time : conditions (sleep, paralyze etc)
};