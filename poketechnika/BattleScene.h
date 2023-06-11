#pragma once
#include "Scene.h"
#include "Pokemon.h"
#include "TextArea.h"

enum class BattleMenu {
	MAIN, MOVES, POKEMON
};

enum class Turn {
	PLAYER, ENEMY
};

class BattleScene :
    public Scene
{
private:
	Drawable background;
	BattleMenu menu;
	Turn currentTurn;
	bool isCatchable;
	int buttonRange[2];
	TextArea battleLog;
	Pokemon playerTeam[6];
	Pokemon enemyTeam[6];
	std::map<int, Pokemon> pokemonTemplate;
	void load_pokemon();
	void load_player_team();
	void setMenuType(InputHandler& ih);
public:
	BattleScene();
	void update(float time_elapsed, InputHandler& ih);
	void render(Renderer& renderer);
	void save_player_team();
	void setRandomEnemy(InputHandler& ih);
};