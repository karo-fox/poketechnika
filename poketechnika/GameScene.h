#pragma once
#include <vector>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "GameObject.h"
#include "Map.h"
//#include "InputHandler.h"


enum class GO {
	PLAYER, CAMERA, POKEMON
};

using GOContainer = std::map<GO, std::vector<std::shared_ptr<GameObject>>>;

class GameScene : public Scene
{
private:
	GOContainer game_objects;
	Map map;
	//InputHandler ih;
	void load_map();
public:
	GameScene();
	void update(float time_elapsed, const InputHandler& ih);
	//void process_input(sf::RenderWindow& window);
	void render(Renderer& render);
};
