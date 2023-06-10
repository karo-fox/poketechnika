#include "GameObject.h"

GameObject::GameObject() : active(false) {}

bool GameObject::isActive() {
	return active;
}

void GameObject::setActive(bool active_)
{
	active = active_;
}

void GameObject::save(pugi::xml_node& node) {}

void GameObject::load(pugi::xml_node& node) {}

void to_xml(GameObject& go, pugi::xml_node& node) {
	go.save(node);
}

void from_xml(GameObject& go, pugi::xml_node& node) {
	go.load(node);
}
