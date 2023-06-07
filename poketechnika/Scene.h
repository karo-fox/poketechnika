#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
//#include <SFML/Graphics.hpp>
//#include "Renderer.h"
//#include "Camera.h"
//
//class Scene
//{
//protected:
//	const std::string texturesPath = "assets/textures/";
//	sf::Texture backgroundTexture;
//	sf::Sprite background;
//	Renderer* renderer;
//	Camera cam;
//public:
//	virtual void draw();
//	virtual void loadTextures();
//	Scene(Renderer* rend);
//	virtual ~Scene();
//};

class Scene {
public:
	virtual ~Scene() = default;
	virtual void update(float time_elapsed) = 0;
	virtual void process_input(sf::RenderWindow& window) = 0;
	virtual void render(Renderer& renderer) = 0;
};
