#pragma once
#include "Scene.h"
#include "MenuInputHandler.h"
#include "MenuUI.h"

class MenuScene : public Scene
{
private:
	MenuInputHandler ih;
	MenuUI ui;
public:
	MenuScene();
	//void loadTextures();
	//void draw();
	void update(float time_elapsed);
	void process_input(sf::RenderWindow& window);
	void render(Renderer& renderer);
};
