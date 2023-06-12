#pragma once
#include <memory>
#include <pugixml.hpp>
#include "GameObject.h"
#include "Drawable.h"
#include "InputHandler.h"
#include "Map.h"

enum class CurrentAnimation {
	IDLE, RUNNING1, RUNNING2, RUNNING3
};

enum class Faceing {
	UP, DOWN, LEFT, RIGHT
};

class Player : public GameObject, public Drawable
{
private:
	float speed;
	sf::Vector2f size;
	std::shared_ptr<Map> _map;
	CurrentAnimation animation;
	Faceing face;
	int animDur;
public:
	Player(const Map& m);

	// Returns the player position
	sf::Vector2f getPosition();

	void update(float elapsedTime, InputHandler& ih) override;
	// Changes player position according to user input and specifies map interactions
	void movementLogic(float elapsedTime, InputHandler& ih);
	void save(pugi::xml_node& node);
	void load(pugi::xml_node& node);
	// Specifies player animation
	void updateSprite();
};
