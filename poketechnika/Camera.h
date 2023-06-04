#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Camera : public GameObject
{
	static sf::Vector2f size;
public:
	static void setCameraSize(int x, int y);
	void update(float elapsedTime);
	bool isWithinCamera(sf::Vector2f pos);
	Camera(int x, int y);
	~Camera();
};