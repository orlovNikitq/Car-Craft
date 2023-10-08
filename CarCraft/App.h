#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
#include "Button.h"
#include "Car.h"
#include "Config.h"
class App {
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Texture carTexture;
    sf::Image heroimage;
    sf::Sprite backgroundSprite;
    sf::Sprite herosprite;
    std::vector<Button> buttons;
    std::vector<Button> bodyButtons;
    std::vector<Button> additionButtons;
    std::vector<Button> menuButtons;
    Car car;
    bool saveFlag;
public:
    App();
    void run();

private:
    void render();
    void processEvent();
    void createBodyButtons();
    void createAdditionButtons();
    void createMenuButtons();
    void createCarImage(bool body, bool turnSignal, bool disks, bool frontAndBack);
    void returnToMainMenu();
    void saveCarImage(std::string path);
};