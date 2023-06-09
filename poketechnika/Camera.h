#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameObject.h"
#include "Map.h"
#include "InputHandler.h"
#include "Player.h"

class Camera : public GameObject
{
	static sf::Vector2f size;
	sf::Vector2f position;
	std::shared_ptr<Player> player;
public:
	Camera(int x, int y, std::shared_ptr<Player> p);
	static void setCameraSize(int x, int y);
	void update(float elapsedTime, const InputHandler& ih);
	bool isWithinCamera(sf::Vector2f pos) const;
};