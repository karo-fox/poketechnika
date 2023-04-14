#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Camera.h"

class Scene
{
protected:
	const std::string texturesPath = "assets/textures/";
	sf::Texture backgroundTexture;
	sf::Sprite background;
	Renderer* renderer;
	Camera* cam;
public:
	virtual void draw();
	virtual void loadTextures();
	Scene(Renderer* rend);
	virtual ~Scene();
};