#include "GameObject.h"

GameObject::GameObject() : active(false) {}

bool GameObject::isActive() {
	return active;
}

void GameObject::setActive(bool active_)
{
	active = active_;
}
