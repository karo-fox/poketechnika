#include <utility>
#include "SceneManager.h"
#include "MenuScene.h"

//
//void SceneManager::changeScene(State change) {
//	delete currScene;
//	switch (change)
//	{
//		case State::MAINMENU:
//			currScene = new MenuScene(rend);
//			scene = State::MAINMENU;
//			break;
//		case State::GAME:
//			currScene = new GameScene(rend);
//			scene = State::GAME;
//			break;
//		default:
//			currScene = new Scene(rend);
//			scene = State::ERROR;
//			break;
//	}
//	currScene->loadTextures();
//}



SceneManager::SceneManager(sf::RenderWindow& window, std::shared_ptr<Scene>&& scene) : active_scene{ std::move(scene) }, renderer{ window } {}

void SceneManager::set_scene(std::shared_ptr<Scene>&& scene) {
	active_scene = std::move(scene);
}

void SceneManager::run_scene(float time_elapsed) {
	active_scene->process_input(renderer.getWindow());
	active_scene->update(time_elapsed);

	renderer.rendClear();
	active_scene->render(renderer);
	renderer.rendDisplay();
}

void SceneManager::set_renderer_scale() {
	renderer.setScale();
}
