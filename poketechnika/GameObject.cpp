#include "GameObject.h"
#include "InputHandler.h"
//#include <iostream>
//#include <vector>

//std::vector<GameObject*>* GameObject::gameObjectsPtr = nullptr;
//InputManager* GameObject::inputManagerPtr = nullptr;

GameObject::GameObject() : active(false) {}

//void GameObject::update(float elapsedTime, const InputHandler& ih) {
//
//}

//void GameObject::add() {
//	gameObjectsPtr->push_back(this);
//}

//void GameObject::remove()
//{
//	for (int i = 0; i < gameObjectsPtr->size(); i++)
//		if (gameObjectsPtr->at(i) == this) gameObjectsPtr->erase(gameObjectsPtr->begin() + i);
//}

//void GameObject::setGameObjectsPtr(std::vector<GameObject*>* ptr) {
//	gameObjectsPtr = ptr;
//}

//void GameObject::setInputManagerPtr(InputManager* ptr) {
//	inputManagerPtr = ptr;
//}

//sf::Vector2f GameObject::getPosition() const {
//	return position;
//}

bool GameObject::isActive() {
	return active;
}

void GameObject::setActive(bool active_)
{
	active = active_;
}
