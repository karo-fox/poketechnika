#include "TextArea.h"
#include <iostream>

sf::Font TextArea::_font{};

TextArea::TextArea(
	const std::string& txt, const sf::Vector2f& position,
	const std::string& texture_file
) : Drawable( texture_file, position, true )
{
	text.setFont(_font);
	text.setString(txt);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color{ 0, 0, 0 });
	textPos = sf::Vector2f(7,  sprite.getGlobalBounds().height - 22);
}

void TextArea::setText(std::string str) {
	text.setString(str);
	textPos = sf::Vector2f(7, sprite.getGlobalBounds().height - 22);
}

void TextArea::addText(std::string str) {
	std::string str_ = text.getString();
	text.setString(str_ + str);
	textPos = textPos - sf::Vector2f(0, 14);
}

void TextArea::load_font(const std::string& font_file) {
	if (!_font.loadFromFile(font_file)) {
		throw Exception("Unable to load font from " + font_file);
	}
}