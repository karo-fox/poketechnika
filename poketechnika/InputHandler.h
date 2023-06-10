#pragma once
#include <set>
#include <map>
#include <SFML/Graphics.hpp>
#include <memory>
#include <cstdlib>
#include <time.h>
#include "actions.h"
#include "State.h"

using ActionsMap = std::map<const sf::Keyboard::Key, Action>;

class InputHandler {
protected:
	State& active_state;
	mutable std::set<Action> active_actions;
	std::map<State, ActionsMap> event_actions;
	std::map<State, ActionsMap> real_time_actions;
public:
	InputHandler(State& state);
	void process_input(sf::RenderWindow& window);
	void reset_actions();
	void add_action(const Action& action) const;
	bool get_action(const Action& action) const;
	bool randomizer(int percent) const;
};
