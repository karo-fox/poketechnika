#include "Pokemon.h"

Pokemon::Pokemon(std::string name_, int lvl_, int xp_, PokemonType type1_, PokemonType type2_, float hp_, float maxhp_, Move move1_, Move move2_, Move move3_, Move move4_)
	: Drawable("assets/textures/pokemon/error.png", sf::Vector2f{0, 0}, true),
	name(name_), lvl(lvl_), xp(xp_), type1(type1_), type2(type2_), hp(hp_), maxhp(maxhp_), move1(move1_), move2(move2_), move3(move3_), move4(move4_) {
	active = false;
}

Pokemon::Pokemon() : Drawable("assets/textures/pokemon/error.png", sf::Vector2f{ 0, 0 }, true)
{
	name = "NULL";
	lvl = 99;
	xp = 9999;
	type1 = PokemonType::NORMAL;
	type2 = PokemonType::NONE;
	hp = 9999;
	maxhp = 9999;
	move1 = Move();
	move2 = Move();
	move3 = Move();
	move4 = Move();
	active = false;
}

void Pokemon::update(float elapsedTime, InputHandler& ih)
{

}

void Pokemon::setOwner(bool isPlayer)
{
	if (isPlayer)
	{
		file = "assets/textures/pokemon/" + name + "_back.png";
		position = sf::Vector2f(150, 281);
		setDrawable();
	}
	else
	{
		file = "assets/textures/pokemon/" + name + "_front.png";
		position = sf::Vector2f(800, -25);
		setDrawable();
	}
}