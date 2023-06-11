#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Text3Button : public Button {
public:
	sf::Text text2;
	sf::Text text3;
	Text3Button(
		const std::string& txt, const std::string& txt2, const std::string& txt3, 
		const Action& action, const sf::Vector2f& position,
		const std::string& texture_file = "assets/textures/button.png"
	);
};
