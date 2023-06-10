#include "Player.h"
#include "actions.h"

Player::Player(const Map& map) 
	: GameObject{}, Drawable{ "assets/textures/player.png", sf::Vector2f{12 * 64, 8 * 64} }, _map{ std::make_shared<Map>(map) }
{
	size = sf::Vector2f(32, 32);
	speed = 0.10f;
}

void Player::update(float elapsedTime, InputHandler& ih)
{
	// Movement logic
	movementLogic(elapsedTime, ih);
}

void Player::movementLogic(float elapsedTime, InputHandler& ih)
{
	// Each if checks for one direction, for both start and end of player graphics (size)
	sf::Vector2f move(0, 0);
	if (ih.get_action(Action::MoveUp) &&
		_map->isPassable(sf::Vector2f(position.x, position.y - speed * elapsedTime)) &&
		_map->isPassable(sf::Vector2f(position.x + size.x, position.y - speed * elapsedTime)))
	{
		move += sf::Vector2f(0, -speed * elapsedTime);
	}
	if (ih.get_action(Action::MoveDown) &&
		_map->isPassable(sf::Vector2f(position.x, position.y + size.y + speed * elapsedTime)) &&
		_map->isPassable(sf::Vector2f(position.x + size.x, position.y + size.y + speed * elapsedTime)))
	{
		move += sf::Vector2f(0, speed * elapsedTime);
	}
	if (ih.get_action(Action::MoveLeft) &&
		_map->isPassable(sf::Vector2f(position.x - speed * elapsedTime, position.y)) &&
		_map->isPassable(sf::Vector2f(position.x - speed * elapsedTime, position.y + size.y)))
	{
		move += sf::Vector2f(-speed * elapsedTime, 0);
	}
	if (ih.get_action(Action::MoveRight) &&
		_map->isPassable(sf::Vector2f(position.x + size.x + speed * elapsedTime, position.y)) &&
		_map->isPassable(sf::Vector2f(position.x + size.x + speed * elapsedTime, position.y + size.y)))
	{
		move += sf::Vector2f(speed * elapsedTime, 0);
	}
	position += move;
	// Checking for encounter
	if (move != sf::Vector2f(0, 0)
		&& _map->isTileType(position + sf::Vector2f(size.x / 2, size.y / 2), tileTypes::BUSH)
		&& ih.randomizer(1))
	{
		ih.add_action(Action::RandomPokemon);
		ih.add_action(Action::ChangeSceneToBattle);
	}
}

sf::Vector2f Player::getPosition()
{
	return position;
}

void Player::save(pugi::xml_node& node) {
	pugi::xml_node active_node = node.child("active");
	active_node.first_child().text().set(active);
}

void Player::load(pugi::xml_node& node) {
	pugi::xml_node active_node = node.child("active");
	active = active_node.first_child().text().as_bool();
}
