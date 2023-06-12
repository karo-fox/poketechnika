#pragma once
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>
#include "InputHandler.h"

// Every GameObject is updated (if it's active) in game loop
class GameObject
{
protected:
	bool active;
public:
	GameObject();
	// Updates the object on appropriate user input
	virtual void update(float elapsedTime, InputHandler& ih) = 0;
	// Saves the object to given node
	virtual void save(pugi::xml_node& node);
	// Loads the object from given node
	virtual void load(pugi::xml_node& node);
	// Sets the value of `active` variable
	void setActive(bool active_);
	// Checks if object is active
	bool isActive();
};

// Saves given GameObject to given xml node
void to_xml(GameObject& go, pugi::xml_node& node);
// Loads given GameObject data from given node
void from_xml(GameObject& go, pugi::xml_node& node);
