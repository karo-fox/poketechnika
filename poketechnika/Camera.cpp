#include "Camera.h"
#include <iostream>

sf::Vector2f Camera::size = sf::Vector2f(0, 0);

void Camera::update(float elapsedTime, InputHandler& ih)
{
	sf::Vector2f player_position = player->getPosition();
	if (size.x < boundaries.x)
	{
		if (player_position.x - (size.x / 2) + 16 > 0 && player_position.x - (size.x / 2) + 16 < boundaries.y - size.x)
			position.x = player_position.x - (size.x / 2) + 16;
	}
	else
	{
		position.x = -((size.x - boundaries.y) / 2);
	}
	if (size.y < boundaries.y)
	{
		if (player_position.y - (size.y / 2) + 16 > 0 && player_position.y - (size.y / 2) + 16 < boundaries.x - size.y)
			position.y = player_position.y - (size.y / 2) + 16;
	}
	else
	{
		position.y = -((size.y - boundaries.x) / 2);
	}
}

bool Camera::isWithinCamera(sf::Vector2f pos) const
{
	return !(
		pos.x < position.x || pos.y < position.y || 
		pos.x > position.x + size.x + 63 || pos.y > position.y + size.y + 63);
}

Camera::Camera(int x, int y, std::shared_ptr<Player> p) : player{ p } {
	position = sf::Vector2f(x, y);
}

void Camera::setCameraSize(int x, int y) {
	size = sf::Vector2f(x, y);
}

sf::Vector2f Camera::getPosition() const
{
	return position;
}

void Camera::setBoundaries(sf::Vector2f bound)
{
	boundaries = bound;
}
