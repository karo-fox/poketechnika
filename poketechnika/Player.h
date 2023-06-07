#pragma once
#include "GameObject.h"
#include "Drawable.h"
#include "InputHandler.h"
#include "Map.h"

class Player : public GameObject, public Drawable
{
private:
	float speed;
	sf::Vector2f size;
	const Map& map;
public:
	Player(const Map& m);
	void update(float elapsedTime, const InputHandler& ih) override;
};