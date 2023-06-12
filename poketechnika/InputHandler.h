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
	std::set<Action> active_actions;
	std::map<State, ActionsMap> event_actions;
	std::map<State, ActionsMap> real_time_actions;
public:
	InputHandler(State& state);
	// processes user input
	void process_input(sf::RenderWindow& window);
	// clears active actions
	void reset_actions();
	// adds action to active actions
	void add_action(const Action& action);
	// checks if given action is present in active actions
	bool get_action(const Action& action);

	// returns random number
	bool randomizer(int percent);
	int randomizer(int start, int number);
};
