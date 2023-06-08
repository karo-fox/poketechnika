#pragma once
#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Map.h"

class GameObject
{
protected:
	bool active;
public:
	GameObject();
	virtual void update(float elapsedTime, const InputHandler& ih, const Map& map) = 0;
	void setActive(bool active_);
	bool isActive();
};