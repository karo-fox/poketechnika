#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

StateActions GameActions{ // as an example
	{ sf::Keyboard::W, Action::MoveUp },
	{ sf::Keyboard::S, Action::MoveDown },
	{ sf::Keyboard::D, Action::MoveRight },
	{ sf::Keyboard::A, Action::MoveLeft },
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
	// Check for real-time actions
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _active_actions.insert(Action::MoveLeft);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _active_actions.insert(Action::MoveRight);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _active_actions.insert(Action::MoveUp);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _active_actions.insert(Action::MoveDown);
	// Check for event-type actions
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