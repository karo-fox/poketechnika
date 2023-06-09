#include "UI.h"

UI::UI(const std::vector<Button>& buttons) 
	: GameObject{}, _buttons {buttons}, _active_idx{} {}

void UI::update(float elapsedTime, const InputHandler& ih) {
	if (ih.get_action(Action::NextItem)) {
		next();
	}
	if (ih.get_action(Action::PreviousItem)) {
		previous();
	}
}

Action UI::click() const {
	return _buttons.at(_active_idx).click();
}

void UI::next() {
	if (_active_idx < _buttons.size() - 1) {
		unselect();
		_active_idx++;
		select();
	}
}

void UI::previous() {
	if (_active_idx > 0) {
		unselect();
		_active_idx--;
		select();
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