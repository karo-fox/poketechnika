#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "GameObject.h"
#include "Map.h"
#include "GameInputHandler.h"
#include "Camera.h"

class GameScene : public Scene
{
private:
	std::vector<std::shared_ptr<GameObject>> game_objects;
	Map map;
	GameInputHandler ih;

	void load_map();
public:
	GameScene();
	void update(float time_elapsed);
	void process_input(sf::RenderWindow& window);
	void render(Renderer& render);
};
