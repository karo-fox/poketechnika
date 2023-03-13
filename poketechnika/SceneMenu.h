#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
class SceneMenu : public Scene
{
public:
	SceneMenu();
	void LoadTextures();
	void DrawScene(sf::RenderWindow& window);
};