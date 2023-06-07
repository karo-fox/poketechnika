#pragma once
#include "state.h"
#include <map>

enum class Action {
	MoveRight, MoveLeft, MoveUp, MoveDown, ChangeSceneToGame, ChangeSceneToMenu, Close
};

static std::map<const Action, const State&> change_scene{
	{ Action::ChangeSceneToMenu, State::MAINMENU },
	{ Action::ChangeSceneToGame, State::GAME },
};
