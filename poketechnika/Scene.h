#pragma once
#include <SFML/Graphics.hpp>
class Scene
{
protected:
	std::string texturesPath = "assets/textures/";
	sf::Texture backgroundTexture;
	sf::Sprite background;
public:
	virtual void draw(sf::RenderWindow& window);
	virtual void loadTextures();
};