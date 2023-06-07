#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Scene.h"
#include "GeneralInputHandler.h"
#include "state.h"

class Game
{
private:
	sf::Clock clock;
	sf::RenderWindow window;
	SceneManager sm;
	std::map<const State, std::shared_ptr<Scene>> scenes;
	GeneralInputHandler gih;

	void process_input();
public:
	Game(int width, int height, bool fullscreen);
	void run();
};
