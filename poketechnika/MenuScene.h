#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
class MenuScene : public Scene
{
public:
	MenuScene(sf::RenderWindow& w);
	void loadTextures();
	void draw();
};