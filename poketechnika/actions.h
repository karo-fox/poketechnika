#pragma once
#include <map>
#include "state.h"

// Action is a result of user input
enum class Action {
	MoveRight, MoveLeft, MoveUp, MoveDown, ChangeSceneToGame, ChangeSceneToMenu, Close
};

// Actions that change scenes
static std::map<Action, State> change_scene{
	{ Action::ChangeSceneToMenu, State::MAINMENU },
	{ Action::ChangeSceneToGame, State::GAME },
};
