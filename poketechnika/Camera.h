#pragma once
#include <SFML/Graphics.hpp>
#include <pugixml.hpp>
#include <memory>
#include "GameObject.h"
#include "Map.h"
#include "InputHandler.h"
#include "Player.h"

// Camera sets the area that is presented to the screen
class Camera : public GameObject
{
	static sf::Vector2f size;
	sf::Vector2f position;
	std::shared_ptr<Player> player;
	sf::Vector2f boundaries;
public:
	Camera(int x, int y, std::shared_ptr<Player> p);
	// Sets dimensions of camera
	static void setCameraSize(int x, int y); 
	//Changes the area presented to the screen according to the player position
	void update(float elapsedTime, InputHandler& ih);
	// Checks if given position is within the camera area
	bool isWithinCamera(sf::Vector2f pos) const;
	// Sets boundaries of area according to the map size
	void setBoundaries(sf::Vector2f bound);
	// Return the position of the camera
	sf::Vector2f getPosition() const;
};