#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Camera : public GameObject
{
	static sf::Vector2i size;
public:
	static void setCameraSize(int x, int y);
	void update();
	bool isWithinCamera(sf::Vector2i pos);
	Camera(int x, int y);
	~Camera();
};