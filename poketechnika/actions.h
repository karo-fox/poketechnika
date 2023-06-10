#pragma once
#include <map>
#include "state.h"

// Action is a result of user input
enum class Action {
	// GAME
	MoveRight, MoveLeft, MoveUp, MoveDown,
	// CHANGE SCENE
	ChangeSceneToGame, ChangeSceneToMenu, ChangeSceneToBattle, 
	// WINDOW
	Close, 
	// BUTTON
	NextItem, PreviousItem, ClickButton,
	// BATTLE MENU
	Exit, AttackMenu, PokemonMenu, Catch, Run,
	// BATTLE
	RandomPokemon,
};

// Actions that change scenes
static std::map<Action, State> change_scene{
	{ Action::ChangeSceneToMenu, State::MAINMENU },
	{ Action::ChangeSceneToGame, State::GAME },
	{ Action::ChangeSceneToBattle, State::BATTLE },
};
