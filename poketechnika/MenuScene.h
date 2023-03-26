#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
class MenuScene : public Scene
{
public:
	MenuScene(Renderer* rend);
	void loadTextures();
	void draw();
};