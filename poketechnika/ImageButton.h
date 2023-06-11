#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Drawable.h"

class ImageButton : public Button {
public:
	Drawable image;
	ImageButton(
		const Action& action, const sf::Vector2f& position, 
		const std::string& texture_file
	);
};
