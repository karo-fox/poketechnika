#pragma once
#include "Scene.h"
#include "Drawable.h"

class BossScene : public Scene {
	Drawable background;
public:
	BossScene();
	void update(float elapsed_time, InputHandler& ih);
	void render(Renderer& renderer);
};
