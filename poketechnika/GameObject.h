#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "InputManager.h"
class GameObject
{
public:
	GameObject();
	virtual void update(float elapsedTime);
	void add();
	void remove();
	sf::Vector2f getPosition() const;
	void setActive(bool active_);
	bool isActive();
	static void setGameObjectsPtr(std::vector<GameObject*>* ptr);
	static std::vector<GameObject*>* gameObjectsPtr;
	static void setInputManagerPtr(InputManager* ptr);
	static InputManager* inputManagerPtr;
protected:
	sf::Vector2f position;
	bool active;
};