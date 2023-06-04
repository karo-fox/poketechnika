#pragma once
#include "GameObject.h"
#include "Map.h"
class Player : public GameObject
{
private:
	float speed;
	Map* mapPtr;
	sf::Vector2f size;
public:
	Player();
	~Player();
	void update(float elapsedTime);
	sf::Texture t;
	sf::Sprite s;
	void setMapPtr(Map* ptr);
};