#include "GameObject.h"
#include <iostream>
#include <vector>

GameObject::GameObject() : position(0,0), active(false) {}

void GameObject::update() {

}

sf::Vector2i GameObject::getPosition() {
	return position;
}