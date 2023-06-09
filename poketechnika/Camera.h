#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Map.h"
#include "InputHandler.h"

class Camera : public GameObject
{
	static sf::Vector2f size;
	sf::Vector2f position;
public:
	Camera(int x, int y);
	static void setCameraSize(int x, int y);
	void update(float elapsedTime, const InputHandler& ih);
	bool isWithinCamera(sf::Vector2f pos) const;
};