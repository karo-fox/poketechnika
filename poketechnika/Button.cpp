#include "Button.h"
#include "Exception.h"

sf::Font Button::_font{};

Button::Button(
	const std::string& txt, const Action& action, const sf::Vector2f& position,
	const std::string& texture_file
) : Drawable{ texture_file, position }, _action{ action }, text{}
{
	text.setFont(_font);
	text.setString(txt);
	text.setCharacterSize(24);
}

Action Button::click() const {
	return _action;
}

void Button::load_font(const std::string& font_file) {
	if (!_font.loadFromFile(font_file)) {
		throw Exception("Unable to load font from " + font_file);
	}
}
