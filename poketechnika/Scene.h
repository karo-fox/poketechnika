#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
class Scene
{
protected:
	const std::string texturesPath = "assets/textures/";
	sf::Texture backgroundTexture;
	sf::Sprite background;
	Renderer renderer;
public:
	virtual void draw();
	virtual void loadTextures();
	Scene(sf::RenderWindow& window);
};