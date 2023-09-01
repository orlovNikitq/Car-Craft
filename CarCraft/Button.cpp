#include "Button.h"
Button::Button(sf::Vector2f position, sf::Vector2f size, const std::string& text) :
    rectangle(size),
    normalColor(sf::Color::White), 
    pressedColor(sf::Color(192, 192, 192)),
    isPressed(false)
{
    font.loadFromFile("arial.ttf");
   

    rectangle.setSize(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(2);
    this->text.setFont(font); 
    this->text.setString(text);
    this->text.setCharacterSize(24); 
    this->text.setFillColor(sf::Color::Black);
    this->text.setPosition(position);
   
}

void  Button::setPressed(bool pressed)
{
    isPressed = pressed;
    if (isPressed) {
        rectangle.setFillColor(pressedColor); 
    }
    else {
        rectangle.setFillColor(normalColor); 
    }

}

void Button::render(sf::RenderWindow& window)
{
    window.draw(rectangle);
    text.setFont(font);
    window.draw(text);
}

sf::RectangleShape& Button::getRectangle()
{
    return rectangle;
}
