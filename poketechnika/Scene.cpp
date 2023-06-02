#include "Scene.h"
#include <SFML/Graphics.hpp>

void Scene::draw(){
	renderer->draw(background);
}

void Scene::loadTextures(){
	backgroundTexture.loadFromFile(texturesPath+"background_scene.png");
	background.setTexture(backgroundTexture);
}


bool Scene::isRendered()
{
	return is_rendered;
}

void Scene::setRendered(bool rendered)
{
	is_rendered = rendered;
}


Scene::Scene(Renderer* rend) : renderer(rend), cam{ 0, 0 } {}

Scene::~Scene() {}
