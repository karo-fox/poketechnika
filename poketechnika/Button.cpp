#include "Button.h"
#include "Exception.h"

sf::Font Button::_font{};

// Text button
Button::Button(
	const std::string& txt, const Action& action, const sf::Vector2f& position,
	const std::string& texture_file
) : Drawable{ texture_file, position, true }, _action{ action }, text{}, 
	_size(sf::Vector2f(96, 32)), type(ButtonType::TEXT)
{
	text.setFont(_font);
	text.setString(txt);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color{ 0, 0, 0 });
}

// Image button
Button::Button(
	const Action& action, const sf::Vector2f& position,
	const std::string& texture_file, sf::Vector2f size
) : Drawable{ texture_file, position, true }, _action{ action }, text{},
	_size(size), type(ButtonType::IMAGE)
{
	text.setFont(_font);
	text.setString("IMAGE ERROR");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color{ 0, 0, 0 });
}

Action Button::click() const {
	return _action;
}

void Button::load_font(const std::string& font_file) {
	if (!_font.loadFromFile(font_file)) {
		throw Exception("Unable to load font from " + font_file);
	}
}