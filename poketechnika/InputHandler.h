#pragma once
#include <set>
#include <map>
#include <SFML/Graphics.hpp>
#include "actions.h"

using ActionsMap = std::map<const sf::Keyboard::Key, Action>;

class InputHandler {
protected:
	std::set<Action> active_actions;
	ActionsMap event_actions;
	ActionsMap real_time_actions;
public:
	InputHandler();
	void process_input(sf::RenderWindow& window);
	void reset_actions();
	bool get_action(const Action& action) const;
};
