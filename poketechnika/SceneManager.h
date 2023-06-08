#pragma once
#include <memory>
#include "Scene.h"
#include "Renderer.h"
#include "MenuScene.h"

class SceneManager
{
private:
	std::shared_ptr<Scene> active_scene;
	Renderer renderer;
public:
	SceneManager(sf::RenderWindow& window, std::shared_ptr<Scene>&& scene = {});
	void set_scene(std::shared_ptr<Scene> &&scene);
	void run_scene(float time_elapsed);
	void set_renderer_scale();
};
