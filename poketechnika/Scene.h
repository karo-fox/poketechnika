#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "InputHandler.h"
#include "UI.h"

// Every Scene processes input, updates it's elements and renders them appropriately
class Scene {
public:
	UI ui;
	virtual ~Scene() = default;
	// updates the scene accoriding to user input
	virtual void update(float time_elapsed, InputHandler& ih) = 0;
	// renders all elements of the scene
	virtual void render(Renderer& renderer) = 0;
};
