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
	: name(name_), lvl(lvl_), xp(xp_), type1(type1_), type2(type2_), hp(hp_), maxhp(maxhp_), move1(move1_), move2(move2_), move3(move3_), move4(move4_) {}

void Pokemon::save(pugi::xml_node& node) {
	node.child("name").first_child().text().set(name.c_str());
	node.child("lvl").first_child().text().set(lvl);
	node.child("xp").first_child().text().set(xp);
	node.child("type1").first_child().text().set(static_cast<int>(type1));
	node.child("type2").first_child().text().set(static_cast<int>(type2));
	node.child("hp").first_child().text().set(hp);
	node.child("maxhp").first_child().text().set(maxhp);

	pugi::xml_node move1_node = node.child("move1");
	move1.save(move1_node);
	pugi::xml_node move2_node = node.child("move2");
	move1.save(move2_node);
	pugi::xml_node move3_node = node.child("move3");
	move1.save(move3_node);
	pugi::xml_node move4_node = node.child("move4");
	move1.save(move4_node);
}

void Pokemon::load(pugi::xml_node& node) {
	name = node.child("name").first_child().text().as_string();
	lvl = node.child("lvl").first_child().text().as_int();
	xp = node.child("xp").first_child().text().as_int();
	type1 = static_cast<PokemonType>(node.child("type1").first_child().text().as_int());
	type2 = static_cast<PokemonType>(node.child("type2").first_child().text().as_int());
	hp = node.child("hp").first_child().text().as_float();
	maxhp = node.child("maxhp").first_child().text().as_float();

	pugi::xml_node move1_node = node.child("move1");
	move1 = load_move(move1_node);
	pugi::xml_node move2_node = node.child("move2");
	move1 = load_move(move2_node);
	pugi::xml_node move3_node = node.child("move3");
	move1 = load_move(move3_node);
	pugi::xml_node move4_node = node.child("move4");
	move1 = load_move(move4_node);
}
