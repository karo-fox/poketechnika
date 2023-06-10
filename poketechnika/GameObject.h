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
	virtual void update(float elapsedTime, InputHandler& ih) = 0;
	virtual void save(pugi::xml_node& node);
	virtual void load(pugi::xml_node& node);
	void setActive(bool active_);
	bool isActive();
};

void to_xml(GameObject& go, pugi::xml_node& node);
void from_xml(GameObject& go, pugi::xml_node& node);
