#include "Camera.h"
#include <iostream>

sf::Vector2i Camera::size = sf::Vector2i(0, 0);

void Camera::update()
{
	// TODO: moving camera when the player is not in center of the map
}

bool Camera::isWithinCamera(sf::Vector2i pos)
{
	if (pos.x < position.x || pos.y < position.y || pos.x > position.x + size.x + 63 || pos.y > position.y + size.y + 63)
		return false;
	return true;
}

Camera::Camera(int x, int y) {
	position = sf::Vector2i(x, y);
}

Camera::~Camera()
{
	//for (int i = 0; i < gameObjectsPtr->size(); i++)
	//	if (gameObjectsPtr->at(i) == this) gameObjectsPtr->erase(gameObjectsPtr->begin()+i);
}

void Camera::setCameraSize(int x, int y) {
	size = sf::Vector2i(x, y);
}