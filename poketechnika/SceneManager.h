#pragma once
#include <memory>
#include "Scene.h"
#include "Renderer.h"
#include "MenuScene.h"
#include "InputHandler.h"

// SceneManager has one scene which is active at the time and uses Scene API to perform main game tasks
class SceneManager
{
private:
	std::shared_ptr<Scene> active_scene;
	Renderer renderer;
public:
	SceneManager(sf::RenderWindow& window, std::shared_ptr<Scene>&& scene = {});
	void set_scene(std::shared_ptr<Scene> &&scene);
	void run_scene(float time_elapsed, const InputHandler& ih);
	void set_renderer_scale();
};
