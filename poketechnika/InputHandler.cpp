#include "InputHandler.h"

InputHandler::InputHandler() : event_actions{}, real_time_actions{}, active_actions {} {}

void InputHandler::process_input(sf::RenderWindow& window) {
	for (auto& elem : real_time_actions) {
		if (sf::Keyboard::isKeyPressed(elem.first)) {
			active_actions.insert(elem.second);
		}
	}
	sf::Event e{};
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			active_actions.insert(Action::Close);
		}
		if (e.type == sf::Event::KeyPressed) {
			auto search = event_actions.find(e.key.code);
			if (search != event_actions.end()) {
				active_actions.insert(event_actions.at(e.key.code));
			}
		}
	}
}

void InputHandler::reset_actions() {
	active_actions.clear();
}

bool InputHandler::get_action(const Action& action) const {
	auto search = active_actions.find(action);
	return search != active_actions.end();
}
