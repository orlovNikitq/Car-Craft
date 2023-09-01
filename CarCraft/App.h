#pragma once
#include"Config.h"
#include"Button.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
class App
{
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::vector<Button> buttons;
public:
    App();
    void run();
private:
    void render();
    void processEvent();
    void update();
};

