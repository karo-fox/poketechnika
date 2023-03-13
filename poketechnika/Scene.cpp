#include "Scene.h"
#include <SFML/Graphics.hpp>

void Scene::draw(sf::RenderWindow& window){
	window.draw(background);
}

void Scene::loadTextures(){
	backgroundTexture.loadFromFile(texturesPath+"background_scene.png");
	background.setTexture(backgroundTexture);
}