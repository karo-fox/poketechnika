#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
class Scene
{
protected:
	std::string texturesPath = "assets/textures/";
	sf::Texture backgroundTexture;
	sf::Sprite background;
	Renderer renderer;
public:
	virtual void draw(sf::RenderWindow& window);
	virtual void loadTextures();
	Scene(sf::RenderWindow& window);
};