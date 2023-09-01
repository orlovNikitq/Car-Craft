#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
class Button
{
private:
    sf::Vector2f position;
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Font font;
    sf::Color normalColor; 
    sf::Color pressedColor; 
    bool isPressed;
public:
    Button(sf::Vector2f position, sf::Vector2f size, const std::string& text);
    void setPressed(bool pressed);
    void render(sf::RenderWindow& window);
    sf::RectangleShape& getRectangle();
};
