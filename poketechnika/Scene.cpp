#include "Scene.h"
#include <SFML/Graphics.hpp>

void Scene::draw(){
	renderer->draw(background);
}

void Scene::loadTextures(){
	backgroundTexture.loadFromFile(texturesPath+"background_scene.png");
	background.setTexture(backgroundTexture);
}

Scene::Scene(Renderer* rend) : renderer(rend) {
	cam = new Camera(0, 0);
}

Scene::~Scene() {
	delete cam;
}