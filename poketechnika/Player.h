#pragma once
#include <memory>
#include "GameObject.h"
#include "Drawable.h"
#include "InputHandler.h"
#include "Map.h"

class Player : public GameObject, public Drawable
{
private:
	float speed;
	sf::Vector2f size;
	std::shared_ptr<Map> _map;
public:
	Player(const Map& m);

	sf::Vector2f getPosition();

	void update(float elapsedTime, InputHandler& ih) override;
	void movementLogic(float elapsedTime, InputHandler& ih);
};
