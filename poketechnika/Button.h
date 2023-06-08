#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "actions.h"

class Button : public Drawable {
private:
	static sf::Font _font;
	const Action _action;
public:
	sf::Text text;

	Button(
		const std::string& txt, const Action& action, const sf::Vector2f& position, 
		const std::string& texture_file = "assets/textures/button.png"
	);
	Action click() const;

	static void load_font(const std::string& font_file = "assets/Roboto-Bold.ttf");
};
 