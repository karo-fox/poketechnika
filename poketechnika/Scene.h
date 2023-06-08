#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"

class Scene {
public:
	virtual ~Scene() = default;
	virtual void update(float time_elapsed) = 0;
	virtual void process_input(sf::RenderWindow& window) = 0;
	virtual void render(Renderer& renderer) = 0;
};
