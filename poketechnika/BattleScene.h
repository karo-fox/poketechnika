#pragma once
#include "Scene.h"
#include "Pokemon.h"

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
	Pokemon playerTeam[6];
	Pokemon enemyTeam[6];
public:
	BattleScene();
	void update(float time_elapsed, InputHandler& ih);
	void render(Renderer& renderer);
};