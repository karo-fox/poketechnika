#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "actions.h"

enum class ButtonType {
	TEXT, IMAGE
};

class Button : public Drawable {
private:
	const Action _action;
	sf::Vector2f _size;
	ButtonType type;
public:
	static sf::Font _font;
	sf::Text text;

	Button(
		const std::string& txt, const Action& action, const sf::Vector2f& position,
		const std::string& texture_file = "assets/textures/button.png"
	);
	Button(
		const Action& action, const sf::Vector2f& position, sf::Vector2f size,
		const std::string& texture_file = "assets/textures/button.png"
	);
	virtual ~Button() = default;
	Action click() const;

	static void load_font(const std::string& font_file = "assets/Roboto-Bold.ttf");
};
 