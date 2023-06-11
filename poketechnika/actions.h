#pragma once
#include <map>
#include "state.h"

// Action is a result of user input
enum class Action {
	// GAME
	MoveRight, MoveLeft, MoveUp, MoveDown,
	// CHANGE SCENE
	ChangeSceneToGame, ChangeSceneToMenu, ChangeSceneToBattle, ChangeSceneToBoss,
	// WINDOW
	Close, 
	// BUTTON
	NextItem, PreviousItem, ClickButton,
	// BATTLE
	Exit, RandomPokemon,
	AttackMenu, PokemonMenu, Catch, Run,
	Attack1, Attack2, Attack3, Attack4, 
	Pokemon1, Pokemon2, Pokemon3, Pokemon4, Pokemon5, Pokemon6,
	// BOSS
	InitBossFight, WINGAME
};

// Actions that change scenes
static std::map<Action, State> change_scene{
	{ Action::ChangeSceneToMenu, State::MAINMENU },
	{ Action::ChangeSceneToGame, State::GAME },
	{ Action::ChangeSceneToBattle, State::BATTLE },
	{ Action::ChangeSceneToBoss, State::BOSS },
};
