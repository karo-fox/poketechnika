#pragma once
#include <map>
#include "Pokemon.h"
#include "Move.h"

std::map<int, Move> moveTemplate = {
	{0, Move()},
	{1, Move("Scratch", PokemonType::NORMAL, 0.4f)},
	{2, Move("Ember", PokemonType::FIRE, 0.4f)},
	{3, Move("Dragon Breath", PokemonType::DRAGON, 0.6f)},
	{4, Move("Fire Fang", PokemonType::FIRE, 0.65f)},
};
