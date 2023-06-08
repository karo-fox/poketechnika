#include "Player.h"
#include <SFML/Graphics.hpp>

//Player::Player()
//{
//	//mapPtr = nullptr;
//
//	size = sf::Vector2f(32, 32);
//	position = sf::Vector2f(12*64, 8*64);
//	
//	speed = 0.10f;
//
//	t.loadFromFile("assets/textures/player.png");
//	s.setTexture(t);
//}

Player::Player(const Map& m) 
	: GameObject{}, Drawable{ "assets/textures/player.png", sf::Vector2f{12*64, 8*64} }
{
	size = sf::Vector2f(32, 32);
	speed = 0.10f;
}

void Player::update(float elapsedTime, const InputHandler& ih, const Map& map)
{
	// Movement logic
	// Each if checks for one direction, for both start and end of player graphics (size)
	sf::Vector2f move(0, 0);
	if (ih.get_action(Action::MoveUp) &&
		map.isPassable(sf::Vector2f(position.x, position.y - speed * elapsedTime)) &&
		map.isPassable(sf::Vector2f(position.x + size.x, position.y - speed * elapsedTime)))
	{
		move += sf::Vector2f(0, -speed * elapsedTime);
	}
	if (ih.get_action(Action::MoveDown) &&
		map.isPassable(sf::Vector2f(position.x, position.y + size.y + speed * elapsedTime)) &&
		map.isPassable(sf::Vector2f(position.x + size.x, position.y + size.y + speed * elapsedTime))) 
	{
		move += sf::Vector2f(0, speed * elapsedTime);
	}
	if (ih.get_action(Action::MoveLeft) &&
		map.isPassable(sf::Vector2f(position.x - speed * elapsedTime, position.y)) &&
		map.isPassable(sf::Vector2f(position.x - speed * elapsedTime, position.y + size.y)))
	{
		move += sf::Vector2f(-speed * elapsedTime, 0);
	}
	if (ih.get_action(Action::MoveRight) &&
		map.isPassable(sf::Vector2f(position.x + size.x + speed * elapsedTime, position.y)) &&
		map.isPassable(sf::Vector2f(position.x + size.x + speed * elapsedTime, position.y + size.y)))
	{
		move += sf::Vector2f(speed * elapsedTime, 0);
	}
	position += move;
}

//void Player::setMapPtr(Map* ptr)
//{
//	mapPtr = ptr;
//}
