#include "SceneManager.h"
#include "MenuScene.h"
#include "GameScene.h"

SceneManager::SceneManager(Renderer* rend_) : rend(rend_) {
	currScene = new MenuScene(rend);
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
			currScene = new MenuScene(rend);
			scene = state::MAINMENU;
			break;
		case state::GAME:
			currScene = new GameScene(rend);
			scene = state::GAME;
			break;
		default:
			currScene = new Scene(rend);
			scene = state::ERROR;
			break;
	}
	currScene->loadTextures();
}

void SceneManager::renderScene() {
	rend->rendClear();
	currScene->draw();
	rend->rendDisplay();
}

state SceneManager::getCurrentScene() {
	return scene;
}