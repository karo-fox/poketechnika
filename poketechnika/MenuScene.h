#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
//#include "InputHandler.h"
#include "Drawable.h"

class MenuScene : public Scene
{
private:
	Drawable background;
public:
	MenuScene();
	void update(float time_elapsed, InputHandler& ih);
	void render(Renderer& renderer);
};
