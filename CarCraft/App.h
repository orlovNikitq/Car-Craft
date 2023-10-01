#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
#include "Button.h"
#include "Car.h"
#include "Config.h"
class App
{
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::vector<Button> buttons;
    std::vector<Button> bodyButtons;
    std::vector<Button> additionButtons;
    std::vector<Button> menuButtons;
    Car car;

public:
    App();
    void run();
private:
    void render();
    void processEvent();
    void update();
    void createBodyButtons();
    void createColorButtons();
    void createAdditionButtons();
    void createCarImage(bool body);
    void createVarImage(bool body, bool turnSignal, bool disks, bool frontAndBack);
    void showSavedCars();
    void createMenuButtons();

};
