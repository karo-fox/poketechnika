#include "ImageButton.h"

ImageButton::ImageButton(
	const Action& action, const sf::Vector2f& position, const std::string& texture_file
) : Button{ action, position, sf::Vector2f{32, 32}, "assets/textures/button_square.png" }, 
	image{ texture_file, position, true }
{}


