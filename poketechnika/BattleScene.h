#pragma once
#include "Scene.h"
class BattleScene :
    public Scene
{
private:
	Drawable background;
public:
	BattleScene();
	void update(float time_elapsed, const InputHandler& ih);
	void render(Renderer& renderer);
};