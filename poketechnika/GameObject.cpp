#include "GameObject.h"
#include <iostream>
#include <vector>

std::vector<GameObject*>* GameObject::gameObjectsPtr = nullptr;

GameObject::GameObject() : position(0,0), active(false) {}

void GameObject::update() {

}

void GameObject::setGameObjectsPtr(std::vector<GameObject*>* ptr) {
	gameObjectsPtr = ptr;
}

sf::Vector2i GameObject::getPosition() {
	return position;
}