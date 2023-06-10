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
	std::map<int, Pokemon> pokemonTemplate;
	void load_pokemon();
	void load_player_team();
public:
	BattleScene();
	void update(float time_elapsed, InputHandler& ih);
	void render(Renderer& renderer);
	void save_player_team();
};