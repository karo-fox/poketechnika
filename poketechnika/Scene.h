#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "InputHandler.h"

// Every Scene processes input, updates it's elements and renders them appropriately
class Scene {
public:
	virtual ~Scene() = default;
	virtual void update(float time_elapsed, const InputHandler& ih) = 0;
	//virtual void process_input(sf::RenderWindow& window) = 0;
	virtual void render(Renderer& renderer) = 0;
};
