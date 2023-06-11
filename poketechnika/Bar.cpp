#include "Bar.h"
#include "Exception.h"

sf::Font Bar::_font{};

Bar::Bar(
	int max_val, int val, const sf::Vector2f pos, 
	const std::string& texture_file
) : Drawable{ texture_file, pos }, max_value{ max_val }, value{ val }, text{},
	progress{ "assets/textures/bar_progress.png", 
		sf::IntRect{0, 0, static_cast<int>(static_cast<float>(value)/max_value * 191), 32 }, 
	pos }
{
	std::string txt = std::to_string(value) + " / " + std::to_string(max_value);
	text.setFont(_font);
	text.setString(txt);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color{ 0, 0, 0 });
}

void Bar::load_font(const std::string& font_file) {
	if (!_font.loadFromFile(font_file)) {
		throw Exception("Unable to load font from " + font_file);
	}
}
