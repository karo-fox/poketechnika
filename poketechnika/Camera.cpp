#include "Camera.h"
#include <iostream>

void Camera::update()
{
	// TODO: moving camera when the player is not in center of the map
}

Camera::Camera(int x, int y) {
	position = sf::Vector2i(x, y);
	gameObjectsPtr->push_back(this);
}

Camera::~Camera()
{
	for (int i = 0; i < gameObjectsPtr->size(); i++)
		if (gameObjectsPtr->at(i) == this) gameObjectsPtr->erase(gameObjectsPtr->begin()+i);
}