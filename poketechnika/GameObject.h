#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	GameObject();
	virtual void update();
	sf::Vector2i getPosition();
protected:
	sf::Vector2i position;
	bool active;
};