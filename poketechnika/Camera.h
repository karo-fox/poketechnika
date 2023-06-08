#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Map.h"

class Camera : public GameObject
{
	static sf::Vector2f size;
	sf::Vector2f position;
public:
	static void setCameraSize(int x, int y);
	void update(float elapsedTime, const InputHandler& ih, const Map& map);
	bool isWithinCamera(sf::Vector2f pos) const;
	Camera(int x, int y);
	//~Camera();
};