#pragma once
#include <map>
#include "state.h"

enum class Action {
	MoveRight, MoveLeft, MoveUp, MoveDown, ChangeSceneToGame, ChangeSceneToMenu, Close
};

static std::map<Action, State> change_scene{
	{ Action::ChangeSceneToMenu, State::MAINMENU },
	{ Action::ChangeSceneToGame, State::GAME },
};
