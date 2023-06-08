#pragma once
#include "Scene.h"
#include "InputHandler.h"
#include "MenuUI.h"
#include "Drawable.h"

class MenuScene : public Scene
{
private:
	InputHandler ih;
	MenuUI ui;
	Drawable background;
public:
	MenuScene();
	//void loadTextures();
	//void draw();
	void update(float time_elapsed);
	void process_input(sf::RenderWindow& window);
	void render(Renderer& renderer);
};
