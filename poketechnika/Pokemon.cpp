#include "Pokemon.h"

Pokemon::Pokemon(std::string name_, int lvl_, int xp_, PokemonType type1_, PokemonType type2_, float hp_, float maxhp_, Move move1_, Move move2_, Move move3_, Move move4_)
	: name(name_), lvl(lvl_), xp(xp_), type1(type1_), type2(type2_), hp(hp_), maxhp(maxhp_), move1(move1_), move2(move2_), move3(move3_), move4(move4_) {}