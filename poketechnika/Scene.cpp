#include "Scene.h"
#include <SFML/Graphics.hpp>

void Scene::DrawScene(sf::RenderWindow& window){
	window.draw(background);
}

void Scene::LoadTextures(){
	backgroundTexture.loadFromFile(texturesPath+"background_scene.png");
	background.setTexture(backgroundTexture);
}