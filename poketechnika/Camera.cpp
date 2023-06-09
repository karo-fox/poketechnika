#include "Camera.h"

sf::Vector2f Camera::size = sf::Vector2f(0, 0);

void Camera::update(float elapsedTime, const InputHandler& ih)
{
	// TODO: moving camera when the player is not in center of the map
}

bool Camera::isWithinCamera(sf::Vector2f pos) const
{
	return !(
		pos.x < position.x || pos.y < position.y || 
		pos.x > position.x + size.x + 63 || pos.y > position.y + size.y + 63);
}

Camera::Camera(int x, int y, const Player& p) : player{ std::make_shared<Player>(p) } {
	position = sf::Vector2f(x, y);
}

void Camera::setCameraSize(int x, int y) {
	size = sf::Vector2f(x, y);
}
