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

std::map<int, Pokemon> pokemonTemplate = {
	{0, Pokemon()},
	{1, Pokemon("Charmander", 1, 0, PokemonType::FIRE, PokemonType::NONE, 10, 10, moveTemplate.at(1), moveTemplate.at(2), moveTemplate.at(3), moveTemplate.at(4))},
};