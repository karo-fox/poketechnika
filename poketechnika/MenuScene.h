#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
class MenuScene : public Scene
{
public:
	MenuScene();
	void loadTextures();
	void draw(sf::RenderWindow& window);
};