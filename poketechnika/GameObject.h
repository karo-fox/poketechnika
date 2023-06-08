#pragma once
#include <SFML/Graphics.hpp>
#include "InputHandler.h"

// Every GameObject is updated (if it's active) in game loop
class GameObject
{
protected:
	bool active;
public:
	GameObject();
	virtual void update(float elapsedTime, const InputHandler& ih) = 0;
	void setActive(bool active_);
	bool isActive();
};