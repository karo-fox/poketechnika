#pragma once
#include "Drawable.h"

class Bar : public Drawable {
private:
	int max_value;
	int value;
public:
	static sf::Font _font;
	sf::Text text;
	Drawable progress;

	Bar(int max_val, int val, const sf::Vector2f pos, 
		const std::string& texture_file = "assets/textures/bar_background.png"
	);
	static void load_font(const std::string& font_file = "assets/Roboto-Bold.ttf");
};
