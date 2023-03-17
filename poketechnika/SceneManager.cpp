#include "SceneManager.h"
#include "MenuScene.h"
#include "GameScene.h"

SceneManager::SceneManager(sf::RenderWindow& w) : window(w) {
	currScene = new MenuScene(window);
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
			currScene = new MenuScene(window);
			scene = state::MAINMENU;
			break;
		case state::GAME:
			currScene = new GameScene(window);
			scene = state::GAME;
			break;
		default:
			currScene = new Scene(window);
			scene = state::ERROR;
			break;
	}
	currScene->loadTextures();
}

void SceneManager::renderScene() {
	window.clear();
	currScene->draw(window);
	window.display();
}

state SceneManager::getCurrentScene() {
	return scene;
}