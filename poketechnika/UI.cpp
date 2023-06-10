#include "UI.h"

UI::UI(const std::vector<Button>& buttons) 
	: GameObject{}, _buttons {buttons}, _active_idx{} {}

void UI::update(float elapsedTime, InputHandler& ih) {
	if (ih.get_action(Action::NextItem)) {
		next();
	}
	if (ih.get_action(Action::PreviousItem)) {
		previous();
	}
	if (_buttons.size() > 0) select();
}

void UI::update(float elapsedTime, InputHandler& ih, int first, int size) {
	if (ih.get_action(Action::Exit)) {
		_active_idx = 0;
	}
	if (ih.get_action(Action::AttackMenu)) {
		_active_idx = 4;
	}
	if (ih.get_action(Action::PokemonMenu)) {
		_active_idx = 8;
	}
	if (ih.get_action(Action::NextItem)) {
		if(_active_idx < size) next();
	}
	if (ih.get_action(Action::PreviousItem)) {
		if(_active_idx > first) previous();
	}
	if (_buttons.size() > 0) select();
}

void UI::resetSelectButton()
{
	for (int i = 0; i < _buttons.size(); i++)
	{
		unselect(i);
	}
}

Action UI::click() const {
	return _buttons.at(_active_idx).click();
}

void UI::next() {
	if (_active_idx < _buttons.size() - 1) {
		unselect();
		_active_idx++;
	}
}

void UI::previous() {
	if (_active_idx > 0) {
		unselect();
		_active_idx--;
	}
}

void UI::select() {
	_buttons.at(_active_idx).sprite.setColor(sf::Color(255, 0, 0));
	_buttons.at(_active_idx).text.setFillColor(sf::Color(255, 255, 255));
}

void UI::unselect() {
	_buttons.at(_active_idx).sprite.setColor(sf::Color(255, 255, 255));
	_buttons.at(_active_idx).text.setFillColor(sf::Color(0, 0, 0));
}

void UI::unselect(int id) {
	_buttons.at(id).sprite.setColor(sf::Color(255, 255, 255));
	_buttons.at(id).text.setFillColor(sf::Color(0, 0, 0));
}