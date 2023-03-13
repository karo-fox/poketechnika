#include "SceneManager.h"
#include "MenuScene.h"
#include "GameScene.h"

SceneManager::SceneManager() {
	currScene = new MenuScene();
	currScene->loadTextures();
	scene = state::MAINMENU;
}

SceneManager::~SceneManager(){
	delete currScene;
}

void SceneManager::changeScene(state change) {
	delete currScene;
	switch (change)
	{
		case state::MAINMENU:
			currScene = new MenuScene();
			scene = state::MAINMENU;
			break;
		case state::GAME:
			currScene = new GameScene();
			scene = state::GAME;
			break;
		default:
			currScene = new Scene();
			scene = state::ERROR;
			break;
	}
	currScene->loadTextures();
}

void SceneManager::renderScene(sf::RenderWindow& window) {
	window.clear();
	currScene->draw(window);
	window.display();
}

state SceneManager::getCurrentScene() {
	return scene;
}