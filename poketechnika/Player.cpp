#include "Player.h"
#include "actions.h"

Player::Player(const Map& map) 
	: GameObject{}, Drawable{ "assets/textures/player.png", sf::Vector2f{12 * 64, 8 * 64} }, _map{ std::make_shared<Map>(map) }
{
	size = sf::Vector2f(32, 32);
	speed = 0.10f;
}

void Player::update(float elapsedTime, const InputHandler& ih)
{
	// Movement logic
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
}
