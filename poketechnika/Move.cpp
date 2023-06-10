#include "Move.h"

Move::Move() : name("ERROR"), type(PokemonType::NORMAL), power(1.0f) {}

Move::Move(std::string name_, PokemonType type_, float power_) : name(name_), type(type_), power(power_) {}