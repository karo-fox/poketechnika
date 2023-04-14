#include "InputManager.h"
#include <SFML/Graphics.hpp>

StateActions GameActions{
	{ sf::Keyboard::W, Action::MoveUp },
	{ sf::Keyboard::S, Action::MoveDown },
	{ sf::Keyboard::A, Action::MoveRight },
	{ sf::Keyboard::D, Action::MoveDown },
};

InputManager::InputManager() {
	ActionsCollection actions{
		{ State::GAME, GameActions },
	};
	_actions = actions;
}

bool InputManager::getAction(Action action) const {
	auto search = _active_actions.find(action);
	return search != _active_actions.end();
}

void InputManager::processInput(sf::RenderWindow& window, const SceneManager& sm) {
	sf::Event e{};
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::KeyPressed) {
			auto& state_actions = _actions.at(sm.getCurrentScene());
			auto search = state_actions.find(e.key.code);
			if (search != state_actions.end()) {
				_active_actions.insert(state_actions.at(e.key.code));
			}
		}
	}
}