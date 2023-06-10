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

void GameObject::load(pugi::xml_node& node) {
	pugi::xml_node active_node = node.child("active");
	active_node.first_child().set_value(std::to_string(active).c_str());
}

void to_xml(GameObject& go, pugi::xml_node& node) {
	go.save(node);
}

void from_xml(GameObject& go, pugi::xml_node& node) {
	go.load(node);
}
