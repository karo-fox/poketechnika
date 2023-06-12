#pragma once
#include <vector>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "GameObject.h"
#include "Map.h"


enum class GO {
	PLAYER, CAMERA, POKEMON
};

using GOContainer = std::map<GO, std::vector<std::shared_ptr<GameObject>>>;

class GameScene : public Scene
{
private:
	GOContainer game_objects;
	Map map;
	void load_map();
public:
	GameScene();
	void update(float time_elapsed, InputHandler& ih);
	void render(Renderer& render);
	// saves GameObjects in GameScene to xml file
	void save_gos();
	// loads GameObjects in GameScene from xml file
	void load_gos();
};
