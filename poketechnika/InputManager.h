#pragma once
#include <set>
#include <SFML/Graphics.hpp>
#include "State.h"

enum class Action {
	MoveRight, MoveLeft, MoveUp, MoveDown, ChangeSceneToGame, ChangeSceneToMenu, Close
};

using StateActions = std::map<const sf::Keyboard::Key, Action>;
using ActionsCollection = std::map<State, StateActions>;

class InputManager {
private:
	std::set<Action> _active_actions{};
	ActionsCollection _actions;
public:
	InputManager();
	bool getAction(Action action) const;
	void processInput(sf::RenderWindow& window, const State& state);
	void reset_actions();
};

