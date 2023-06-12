#pragma once
#include "Drawable.h"
#include "Exception.h"

class TextArea :
    public Drawable
{
private:
    static sf::Font _font;
public:
    sf::Text text;
    sf::Vector2f textPos;
    TextArea(
        const std::string& txt, const sf::Vector2f& position,
        const std::string& texture_file = "assets/textures/textarea.png"
    );
    // set's new text
    void setText(std::string str);
    // add text
    void addText(std::string str);
    // loads font from file
    static void load_font(const std::string& font_file = "assets/Roboto-Bold.ttf");
};