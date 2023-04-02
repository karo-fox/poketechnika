#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class GameObject
{
public:
	GameObject();
	virtual void update();
	sf::Vector2i getPosition();
	static void setGameObjectsPtr(std::vector<GameObject*>* ptr);
	static std::vector<GameObject*>* gameObjectsPtr;
protected:
	sf::Vector2i position;
	bool active;
};