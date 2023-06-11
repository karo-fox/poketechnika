#include "Text3Button.h"

Text3Button::Text3Button(
	const std::string& txt, const std::string& txt2, const std::string& txt3, 
	const Action& action, const sf::Vector2f& position, const std::string& texture_file
) : Button{ txt, action, position, texture_file }, text2{}, text3{}
{
	text2.setFont(_font);
	text2.setString(txt2);
	text2.setCharacterSize(20);
	text2.setFillColor(sf::Color{ 0, 0, 0 });
	text3.setFont(_font);
	text3.setString(txt3);
	text3.setCharacterSize(20);
	text3.setFillColor(sf::Color{ 0, 0, 0 });
}

void Text3Button::setText(std::string t1, std::string t2, std::string t3)
{
	text.setString(t1);
	text2.setString(t2);
	text3.setString(t3);
}