#include <utility>
#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window, std::shared_ptr<Scene>&& scene) 
	: active_scene{ std::move(scene) }, renderer{ window } {}

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
