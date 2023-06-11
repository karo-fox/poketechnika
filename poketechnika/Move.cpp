#include "Move.h"

Move::Move() : name("ERROR"), type(PokemonType::NORMAL), power(1.0f) {}

Move::Move(std::string name_, PokemonType type_, float power_)
	: name{ name_ }, type{ type_ }, power{ power_ } {}

std::vector<std::string> Move::data() {
	static std::vector<std::string> types_string{
		"", "normal", "fire", "water", "electric", "grass", "ice", "fighting",
		"poison", "ground", "flying", "psychic", "bug", "rock", "ghost", "dragon",
		"dark", "steel", "fairy"
	};
	return std::vector<std::string>{
		name, types_string.at(static_cast<int>(type)), std::to_string(power)
	};
}

Move load_move(pugi::xml_node& node) {
	std::string name = node.child("name").first_child().text().as_string();
	PokemonType type = static_cast<PokemonType>(node.child("type").first_child().text().as_int());
	float power = node.child("power").first_child().text().as_float();
	Move move{ name, type, power };
	return move;
}

void Move::save(pugi::xml_node& node) {
	node.child("name").first_child().text().set(name.c_str());
	node.child("type").first_child().text().set(static_cast<int>(type));
	node.child("power").first_child().text().set(power);
}

PokemonType Move::getType() {
	return type;
}

float Move::getModifier(PokemonType attack, PokemonType pokemon_first, PokemonType pokemon_second)
{
	if (attack == PokemonType::NORMAL)
	{
		if (
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
			
		if (
			pokemon_first == PokemonType::GHOST || pokemon_second == PokemonType::GHOST
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::FIRE)
	{
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::WATER || pokemon_second == PokemonType::WATER ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK ||
			pokemon_first == PokemonType::DRAGON || pokemon_second == PokemonType::DRAGON
			) return 0.5f;
		if (
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::ICE || pokemon_second == PokemonType::ICE ||
			pokemon_first == PokemonType::BUG || pokemon_second == PokemonType::BUG ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::WATER)
	{
		if (
			pokemon_first == PokemonType::WATER || pokemon_second == PokemonType::WATER ||
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::DRAGON || pokemon_second == PokemonType::DRAGON
			) return 0.5f;
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::GROUND || pokemon_second == PokemonType::GROUND ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::ELECTRIC)
	{
		if (
			pokemon_first == PokemonType::ELECTRIC || pokemon_second == PokemonType::ELECTRIC ||
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::DRAGON || pokemon_second == PokemonType::DRAGON
			) return 0.5f;
		if (
			pokemon_first == PokemonType::WATER || pokemon_second == PokemonType::WATER ||
			pokemon_first == PokemonType::FLYING || pokemon_second == PokemonType::FLYING
			) return 2.0f;
		if (
			pokemon_first == PokemonType::GROUND || pokemon_second == PokemonType::GROUND
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::GRASS)
	{
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::POISON || pokemon_second == PokemonType::POISON ||
			pokemon_first == PokemonType::FLYING || pokemon_second == PokemonType::FLYING ||
			pokemon_first == PokemonType::BUG || pokemon_second == PokemonType::BUG ||
			pokemon_first == PokemonType::DRAGON || pokemon_second == PokemonType::DRAGON ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::WATER || pokemon_second == PokemonType::WATER ||
			pokemon_first == PokemonType::GROUND || pokemon_second == PokemonType::GROUND ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::ICE)
	{
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::WATER || pokemon_second == PokemonType::WATER ||
			pokemon_first == PokemonType::ICE || pokemon_second == PokemonType::ICE ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::GROUND || pokemon_second == PokemonType::GROUND ||
			pokemon_first == PokemonType::FLYING || pokemon_second == PokemonType::FLYING ||
			pokemon_first == PokemonType::DRAGON || pokemon_second == PokemonType::DRAGON
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::FIGHTING)
	{
		if (
			pokemon_first == PokemonType::POISON || pokemon_second == PokemonType::POISON ||
			pokemon_first == PokemonType::FLYING || pokemon_second == PokemonType::FLYING ||
			pokemon_first == PokemonType::PSYCHIC || pokemon_second == PokemonType::PSYCHIC ||
			pokemon_first == PokemonType::BUG || pokemon_second == PokemonType::BUG ||
			pokemon_first == PokemonType::FAIRY || pokemon_second == PokemonType::FAIRY
			) return 0.5f;
		if (
			pokemon_first == PokemonType::NORMAL || pokemon_second == PokemonType::NORMAL ||
			pokemon_first == PokemonType::ICE || pokemon_second == PokemonType::ICE ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK ||
			pokemon_first == PokemonType::DARK || pokemon_second == PokemonType::DARK ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 2.0f;
		if (
			pokemon_first == PokemonType::GHOST || pokemon_second == PokemonType::GHOST
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::POISON)
	{
		if (
			pokemon_first == PokemonType::POISON || pokemon_second == PokemonType::POISON ||
			pokemon_first == PokemonType::GROUND || pokemon_second == PokemonType::GROUND ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK ||
			pokemon_first == PokemonType::GHOST || pokemon_second == PokemonType::GHOST
			) return 0.5f;
		if (
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::FAIRY || pokemon_second == PokemonType::FAIRY
			) return 2.0f;
		if (
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::GROUND)
	{
		if (
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::BUG || pokemon_second == PokemonType::BUG
			) return 0.5f;
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::ELECTRIC || pokemon_second == PokemonType::ELECTRIC ||
			pokemon_first == PokemonType::POISON || pokemon_second == PokemonType::POISON ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 2.0f;
		if (
			pokemon_first == PokemonType::FLYING || pokemon_second == PokemonType::FLYING
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::FLYING)
	{
		if (
			pokemon_first == PokemonType::ELECTRIC || pokemon_second == PokemonType::ELECTRIC ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::FIGHTING || pokemon_second == PokemonType::FIGHTING ||
			pokemon_first == PokemonType::BUG || pokemon_second == PokemonType::BUG
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::PSYCHIC)
	{
		if (
			pokemon_first == PokemonType::PSYCHIC || pokemon_second == PokemonType::PSYCHIC ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::FIGHTING || pokemon_second == PokemonType::FIGHTING ||
			pokemon_first == PokemonType::POISON || pokemon_second == PokemonType::POISON
			) return 2.0f;
		if (
			pokemon_first == PokemonType::DARK || pokemon_second == PokemonType::DARK
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::BUG)
	{
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::FIGHTING || pokemon_second == PokemonType::FIGHTING ||
			pokemon_first == PokemonType::POISON || pokemon_second == PokemonType::POISON ||
			pokemon_first == PokemonType::FLYING || pokemon_second == PokemonType::FLYING ||
			pokemon_first == PokemonType::GHOST || pokemon_second == PokemonType::GHOST ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL ||
			pokemon_first == PokemonType::FAIRY || pokemon_second == PokemonType::FAIRY
			) return 0.5f;
		if (
			pokemon_first == PokemonType::GRASS || pokemon_second == PokemonType::GRASS ||
			pokemon_first == PokemonType::PSYCHIC || pokemon_second == PokemonType::PSYCHIC ||
			pokemon_first == PokemonType::DARK || pokemon_second == PokemonType::DARK

			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::ROCK)
	{
		if (
			pokemon_first == PokemonType::FIGHTING || pokemon_second == PokemonType::FIGHTING ||
			pokemon_first == PokemonType::GROUND || pokemon_second == PokemonType::GROUND ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::ICE || pokemon_second == PokemonType::ICE ||
			pokemon_first == PokemonType::FLYING || pokemon_second == PokemonType::FLYING ||
			pokemon_first == PokemonType::BUG || pokemon_second == PokemonType::BUG
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::GHOST)
	{
		if (
			pokemon_first == PokemonType::DARK || pokemon_second == PokemonType::DARK
			) return 0.5f;
		if (
			pokemon_first == PokemonType::PSYCHIC || pokemon_second == PokemonType::PSYCHIC ||
			pokemon_first == PokemonType::GHOST || pokemon_second == PokemonType::GHOST
			) return 2.0f;
		if (
			pokemon_first == PokemonType::NORMAL || pokemon_second == PokemonType::NORMAL
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::DRAGON)
	{
		if (
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::DRAGON || pokemon_second == PokemonType::DRAGON
			) return 2.0f;
		if (
			pokemon_first == PokemonType::FAIRY || pokemon_second == PokemonType::FAIRY
			) return 0.0f;
		return 1.0f;
	}
	if (attack == PokemonType::DARK)
	{
		if (
			pokemon_first == PokemonType::FIGHTING || pokemon_second == PokemonType::FIGHTING ||
			pokemon_first == PokemonType::DARK || pokemon_second == PokemonType::DARK ||
			pokemon_first == PokemonType::FAIRY || pokemon_second == PokemonType::FAIRY
			) return 0.5f;
		if (
			pokemon_first == PokemonType::PSYCHIC || pokemon_second == PokemonType::PSYCHIC ||
			pokemon_first == PokemonType::GHOST || pokemon_second == PokemonType::GHOST
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::STEEL)
	{
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::WATER || pokemon_second == PokemonType::WATER ||
			pokemon_first == PokemonType::ELECTRIC || pokemon_second == PokemonType::ELECTRIC ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::ICE || pokemon_second == PokemonType::ICE ||
			pokemon_first == PokemonType::ROCK || pokemon_second == PokemonType::ROCK ||
			pokemon_first == PokemonType::FAIRY || pokemon_second == PokemonType::FAIRY
			) return 2.0f;
		return 1.0f;
	}
	if (attack == PokemonType::FAIRY)
	{
		if (
			pokemon_first == PokemonType::FIRE || pokemon_second == PokemonType::FIRE ||
			pokemon_first == PokemonType::POISON || pokemon_second == PokemonType::POISON ||
			pokemon_first == PokemonType::STEEL || pokemon_second == PokemonType::STEEL
			) return 0.5f;
		if (
			pokemon_first == PokemonType::FIGHTING || pokemon_second == PokemonType::FIGHTING ||
			pokemon_first == PokemonType::DRAGON || pokemon_second == PokemonType::DRAGON ||
			pokemon_first == PokemonType::DARK || pokemon_second == PokemonType::DARK
			) return 2.0f;
		return 1.0f;
	}
	return 1.0f;
}

std::string Move::getName() {
	return name;
}

float Move::getPower() {
	return power;
}