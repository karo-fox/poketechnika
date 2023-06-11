#include "Pokemon.h"

Pokemon::Pokemon(std::string name_, int lvl_, int xp_, PokemonType type1_, PokemonType type2_, float hp_, float maxhp_, Move move1_, Move move2_, Move move3_, Move move4_, const std::string& front_texture, const std::string& back_texture)
	: front(front_texture, sf::Vector2f{ 800, -25 }, true), back(back_texture, sf::Vector2f{ 150, 281 }, true),
	name(name_), lvl(lvl_), xp(xp_), type1(type1_), type2(type2_), hp(hp_), maxhp(maxhp_), move1(move1_), move2(move2_), move3(move3_), move4(move4_) {
	active = false;
}

Pokemon::Pokemon() : front("assets/textures/pokemon/error.png", sf::Vector2f{ 800, -25 }, true), back("assets/textures/pokemon/error.png", sf::Vector2f{ 150, 281 }, true)
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

void Pokemon::update(float elapsedTime, InputHandler& ih) {}

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
	move2.save(move2_node);
	pugi::xml_node move3_node = node.child("move3");
	move3.save(move3_node);
	pugi::xml_node move4_node = node.child("move4");
	move4.save(move4_node);

	pugi::xml_node active_node = node.child("active");
	active_node.first_child().text().set(active);
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
	move2 = load_move(move2_node);
	pugi::xml_node move3_node = node.child("move3");
	move3 = load_move(move3_node);
	pugi::xml_node move4_node = node.child("move4");
	move4 = load_move(move4_node);

	front = Drawable{ node.child("front").first_child().text().as_string(), front.position, front.isScalable() };
	back = Drawable{ node.child("back").first_child().text().as_string(), back.position, back.isScalable() };

	pugi::xml_node active_node = node.child("active");
	active = active_node.first_child().text().as_bool();
}

std::string Pokemon::getName() {
	return name;
}

std::vector<std::string> Pokemon::getMoveData(int move_idx) {
	auto& move = move1;
	switch (move_idx) {
	case 1:
		move = move1;
		break;
	case 2:
		move = move2;
		break;
	case 3:
		move = move3;
		break;
	case 4:
		move = move4;
		break;
	default:
		move = move1;
		break;
	}
	return move.data();
}
