#pragma once

enum class PokemonType
{
	NONE, NORMAL, FIRE, WATER, ELECTRIC, GRASS, ICE, FIGHTING, POISON, GROUND, FLYING, PSYCHIC, BUG, ROCK, GHOST, DRAGON, DARK, STEEL, FAIRY 
};


enum class Side { front, back };

//TODO if time : Add conditions (sleep, paralyze etc)

//TODO Move effectivness (ex. Fire vs Fire -> x0.5, Fire vs Grass -> x2, Normal vs Ghost -> x0)