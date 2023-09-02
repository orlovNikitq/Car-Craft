#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
class Button
{
private:
    
    sf::RectangleShape rectangle;
    sf::Text text;
    
    sf::Color normalColor; 
    sf::Color pressedColor; 
    sf::Texture buttonTexture;
    bool isPressed;
    sf::Vector2f position;
    sf::Font font;
    sf::Vector2f size;
public:
    Button(sf::Vector2f position, sf::Vector2f size, const std::string& text);
    void setPressed(bool pressed);
    sf::RectangleShape& getRectangle();
    void render(sf::RenderWindow& window);  
};
