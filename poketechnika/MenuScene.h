#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "InputHandler.h"
#include "Drawable.h"

class MenuScene : public Scene
{
private:
	InputHandler ih;
	Drawable background;
public:
	MenuScene();
	void update(float time_elapsed);
	void process_input(sf::RenderWindow& window);
	void render(Renderer& renderer);
};
