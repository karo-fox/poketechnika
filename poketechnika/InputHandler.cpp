#include "InputHandler.h"

const std::map<State, ActionsMap> events{
{ State::MAINMENU, {
	{ sf::Keyboard::Down, Action::NextItem },
	{ sf::Keyboard::Up, Action::PreviousItem },
	{ sf::Keyboard::Enter, Action::ClickButton },
}},
{ State::GAME, {
	{ sf::Keyboard::Escape, Action::ChangeSceneToMenu },
}},
{ State::BATTLE, {
	{ sf::Keyboard::Right, Action::NextItem },
	{ sf::Keyboard::Left, Action::PreviousItem },
	{ sf::Keyboard::Enter, Action::ClickButton },
	{ sf::Keyboard::Escape, Action::Exit },
}}
};

const std::map<State, ActionsMap> real_time{
{ State::MAINMENU, {} },
{ State::GAME, {
	{ sf::Keyboard::W, Action::MoveUp },
	{ sf::Keyboard::S, Action::MoveDown },
	{ sf::Keyboard::D, Action::MoveRight },
	{ sf::Keyboard::A, Action::MoveLeft }
}},
{ State::BATTLE, {} },
};

InputHandler::InputHandler(State& state)
	: event_actions{ events }, real_time_actions{ real_time }, 
	active_actions{}, active_state{ state }
{
	srand(time(NULL));
}

void InputHandler::process_input(sf::RenderWindow& window) {
	for (auto& elem : real_time_actions.at(active_state)) {
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
			auto search = event_actions.at(active_state).find(e.key.code);
			if (search != event_actions.at(active_state).end()) {
				active_actions.insert(event_actions.at(active_state).at(e.key.code));
			}
		}
	}
}

void InputHandler::reset_actions() {
	active_actions.clear();
}

bool InputHandler::get_action(const Action& action)  {
	auto search = active_actions.find(action);
	return search != active_actions.end();
}

void InputHandler::add_action(const Action& action)  {
	active_actions.insert(action);
}

bool InputHandler::randomizer(int percent) 
{
	int random = std::rand() % 100;
	if (random <= percent) return true;
	else return false;
}