#include "SceneManager.h"
#include "MenuScene.h"
#include "GameScene.h"

SceneManager::SceneManager(Renderer* rend_) : rend(rend_) {
	currScene = nullptr;
	scene = State::ERROR;
}

SceneManager::~SceneManager(){
	delete currScene;
}

void SceneManager::createFirstScene() {
	currScene = new MenuScene(rend);
	currScene->loadTextures();
	scene = State::MAINMENU;
}

void SceneManager::changeScene(State change) {
	delete currScene;
	switch (change)
	{
		case State::MAINMENU:
			currScene = new MenuScene(rend);
			scene = State::MAINMENU;
			break;
		case State::GAME:
			currScene = new GameScene(rend);
			scene = State::GAME;
			break;
		default:
			currScene = new Scene(rend);
			scene = State::ERROR;
			break;
	}
	currScene->loadTextures();
}

void SceneManager::renderScene() {
	rend->rendClear();
	currScene->draw();
	rend->rendDisplay();
}

State SceneManager::getCurrentScene() const {
	return scene;
}