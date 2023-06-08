#include "UI.h"

UI::UI(const std::vector<Button>& buttons) 
	: _buttons{ buttons }, _active_idx{} {}

void UI::next() {
	if (_active_idx < _buttons.size()) {
		_buttons.at(_active_idx).sprite.setColor(sf::Color(255, 255, 255));
		_active_idx++;
		_buttons.at(_active_idx).sprite.setColor(sf::Color(255, 0, 0));
	}
}

void UI::previous() {
	if (_active_idx > 0) {
		_buttons.at(_active_idx).sprite.setColor(sf::Color(255, 255, 255));
		_active_idx--;
		_buttons.at(_active_idx).sprite.setColor(sf::Color(255, 0, 0));
	}
}
