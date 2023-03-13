#include "SceneManager.h"
#include "SceneMenu.h"
#include "SceneGame.h"

SceneManager::SceneManager() {
	currScene = new SceneMenu();
	currScene->LoadTextures();
	scene = state::MAINMENU;
}

SceneManager::~SceneManager(){
	delete currScene;
}

void SceneManager::ChangeScene(state change) {
	delete currScene;
	switch (change)
	{
		case state::MAINMENU:
			currScene = new SceneMenu();
			scene = state::MAINMENU;
			break;
		case state::GAME:
			currScene = new SceneGame();
			scene = state::GAME;
			break;
		default:
			currScene = new Scene();
			scene = state::ERROR;
			break;
	}
	currScene->LoadTextures();
}

void SceneManager::RenderScene(sf::RenderWindow& window) {
	window.clear();
	currScene->DrawScene(window);
	window.display();
}

state SceneManager::getCurrentScene() {
	return scene;
}