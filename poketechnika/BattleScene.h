#pragma once
#include "Scene.h"

enum class BattleMenu {
	MAIN, MOVES, POKEMON
};

class BattleScene :
    public Scene
{
private:
	Drawable background;
	BattleMenu menu;
	int buttonRange[2];
public:
	BattleScene();
	void update(float time_elapsed, const InputHandler& ih);
	void render(Renderer& renderer);
};