#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"
class Button {
private:
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Color normalColor;
    sf::Color pressedColor;
    sf::Texture buttonTexture;
    sf::Vector2f position;
    sf::Font font;
    sf::Vector2f size;
    bool isPressed;
    bool isPlus;

public:
    Button(sf::Vector2f position, sf::Vector2f size, const std::string& text);
    void setPressed(bool pressed);
    sf::RectangleShape& getRectangle();
    void render(sf::RenderWindow& window);
    void setText(const std::string& newText);
};