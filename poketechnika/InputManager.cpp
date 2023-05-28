#include "InputManager.h"
#include <SFML/Graphics.hpp>

StateActions GameActions{ // as an example
	{ sf::Keyboard::W, Action::MoveUp },
	{ sf::Keyboard::S, Action::MoveDown },
	{ sf::Keyboard::A, Action::MoveRight },
	{ sf::Keyboard::D, Action::MoveDown },
	{ sf::Keyboard::L, Action::ChangeSceneToMenu },
	{ sf::Keyboard::Escape, Action::Close },
};
StateActions MenuActions{
	{ sf::Keyboard::L, Action::ChangeSceneToGame },
	{ sf::Keyboard::Escape, Action::Close },
};

InputManager::InputManager() {
	ActionsCollection actions{
		{ State::GAME, GameActions },
		{ State::MAINMENU, MenuActions },
	};
	_actions = actions;
}

bool InputManager::getAction(Action action) const {
	auto search = _active_actions.find(action);
	return search != _active_actions.end();
}

void InputManager::processInput(sf::RenderWindow& window, const State& state) {
	sf::Event e{};
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			_active_actions.insert(Action::Close);
		}
		if (e.type == sf::Event::KeyPressed) {
			auto& state_actions = _actions.at(state);
			auto search = state_actions.find(e.key.code);
			if (search != state_actions.end()) {
				_active_actions.insert(state_actions.at(e.key.code));
			}
		}
	}
}

void InputManager::reset_actions() {
	_active_actions.clear();
}