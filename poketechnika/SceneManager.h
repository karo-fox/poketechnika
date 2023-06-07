#pragma once
#include <memory>
#include "Scene.h"
#include "Renderer.h"
#include "MenuScene.h"

class SceneManager
{
//	Scene* currScene;
//	State scene;
//	Renderer* rend;
//public:
//	SceneManager(Renderer* rend_);
//	virtual ~SceneManager();
//	void createFirstScene();
//	void renderScene();
//	void changeScene(State change);
//	Scene getCurrentScene() const;
//	State getSceneType() const;
private:
	std::shared_ptr<Scene> active_scene;
	Renderer renderer;
public:
	SceneManager(sf::RenderWindow& window, std::shared_ptr<Scene>&& scene = std::make_shared<MenuScene>());
	void set_scene(std::shared_ptr<Scene> &&scene);
	void run_scene(float time_elapsed);
	void set_renderer_scale();
};
