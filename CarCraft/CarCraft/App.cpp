#include "App.h"
App::App() :
    window(sf::VideoMode(WINDOW_W, WINDOW_H), "Car Craft")
{
    backgroundTexture.loadFromFile("background.jpeg");
    backgroundSprite.setTexture(backgroundTexture);
    buttons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 100, WINDOW_H / 2 - 225), sf::Vector2f(270, 50), "Create a new machine"));
    buttons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 100, WINDOW_H / 2 - 150), sf::Vector2f(270, 50), "Saved machines"));
    buttons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 100, WINDOW_H / 2 - 75), sf::Vector2f(270, 50), "List of saved machines"));
    buttons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 100, WINDOW_H / 2 - 0), sf::Vector2f(270, 50), "Exit"));
}

void App::run()
{
    while (window.isOpen()) {
        processEvent();
        update();
        render();
    }
}

void App::render()
{
    window.clear();
    window.draw(backgroundSprite);
    for (auto& button : buttons) {
        button.render(window);
    }
    window.display();
}

void App::processEvent()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f localPosition(event.mouseButton.x, event.mouseButton.y);
            for (int i = 0; i < buttons.size(); ++i) {
                if (buttons[i].getRectangle().getGlobalBounds().contains(localPosition)) {
                    std::cout << "Нажата кнопка " << i << std::endl;
                    buttons[i].setPressed(true);
                    if (i == 0) {

                    }
                    else if (i == 1) {

                    }
                    else if (i == 2) {

                    }
                    else if (i == 3) {
                        window.close();
                    }

                }
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            for (int i = 0; i < buttons.size(); ++i) {
                buttons[i].setPressed(false); 
            }
        }
    }
}

void App::update()
{
}

