#include "App.h"
App::App() :
    window(sf::VideoMode(WINDOW_W, WINDOW_H), "Car Craft")
{
    backgroundTexture.loadFromFile("background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    buttons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 100, WINDOW_H / 2 - 225), sf::Vector2f(270, 50), "Create a new machine"));
    buttons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 100, WINDOW_H / 2 - 150), sf::Vector2f(270, 50), "Saved machines"));
    buttons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 100, WINDOW_H / 2 - 75), sf::Vector2f(270, 50), "Exit"));
}

void App::showSavedCars() {

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
    for (auto& button : bodyButtons) {
        button.render(window);
    }
    for (auto& button : buttons) {
        button.render(window);
    }
    for (auto& button : menuButtons) {
        button.render(window);
    }
    for (auto& button : additionButtons) {
        button.render(window);
    }

    window.display();
}

void App::createVarImage(bool body, bool turnSignal, bool disks, bool frontAndBack) {
    std::cout << "�����" << std::endl;
    std::cout << body << std::endl;
    std::cout << turnSignal << std::endl;
    std::cout << disks << std::endl;
    std::cout << frontAndBack << std::endl;
    std::string path = car.getPath(body);
    sf::Image heroimage;
    heroimage.loadFromFile(path);
    sf::Texture carTexture;
    carTexture.loadFromImage(heroimage);
    sf::Sprite herosprite;
    herosprite.setTexture(carTexture);
    herosprite.setPosition(50, 25);
    window.draw(herosprite);
    /*if (carTexture.loadFromFile(path)) {
        sf::Sprite carSprite(carTexture);
        window.draw(carSprite);
    }
    else {
        std::cerr << "�� ������� ��������� �������� ����������: " << path << std::endl;
    }*/
    std::cout << "�����" << std::endl;
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

            for (int i = 0; i < buttons.size(); i++) {
                if (buttons[i].getRectangle().getGlobalBounds().contains(localPosition)) {
                    std::cout << "������ ������ " << i << std::endl;
                    buttons[i].setPressed(true);
                    if (i == 0) {
                        createBodyButtons();
                    }
                    else if (i == 1) {
                        if (car.flag == false)
                            showSavedCars();
                    }
                    else if (i == 2) {
                        window.close();
                    }
                }
            }

            for (int i = 0; i < bodyButtons.size(); i++) {
                if (bodyButtons[i].getRectangle().getGlobalBounds().contains(localPosition)) {
                    std::cout << "������ bodyButton " << i << std::endl;
                    bodyButtons[i].setPressed(true);
                    if (i == 0) {
                        car.bodyFlag = false;
                    }
                    else if (i == 1) {
                        car.bodyFlag = true;
                    }
                    createAdditionButtons();
                }
            }
            for (int i = 0; i < additionButtons.size(); i++) {
                if (additionButtons[i].getRectangle().getGlobalBounds().contains(localPosition)) {
                    additionButtons[i].setPressed(true);
                    if (i == 0) {
                        additionButtons[i].setText("Turn signal");
                        car.turnSignal = !car.turnSignal;
                    }
                    else if (i == 1) {
                        additionButtons[i].setText("Disks");
                        car.disks = !car.disks;
                    }
                    else if (i == 2) {
                        additionButtons[i].setText("Front and back");
                        car.frontAndBack = !car.frontAndBack;
                    }
                    else if (i == 3) {
                        std::cout << "bodyFlag: " << car.bodyFlag << ", turnSignal: " << car.turnSignal << ", disks: " << car.disks << ", frontAndBack: " << car.frontAndBack << std::endl;
                        car.path = car.getPath(car.bodyFlag);
                        createVarImage(car.bodyFlag, car.turnSignal, car.disks, car.frontAndBack);
                        additionButtons.clear();
                        //    createMenuButtons();
                    }
                }
            }




        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            for (int i = 0; i < buttons.size(); i++) {
                buttons[i].setPressed(false);
            }
            for (int i = 0; i < bodyButtons.size(); i++) {
                bodyButtons[i].setPressed(false);
            }
            for (int i = 0; i < menuButtons.size(); i++) {
                menuButtons[i].setPressed(false);
            }
            for (int i = 0; i < additionButtons.size(); i++) {
                additionButtons[i].setPressed(false);
            }
        }
    }
}

void App::createBodyButtons() {
    buttons.clear();

    bodyButtons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 50, WINDOW_H - 425), sf::Vector2f(170, 50), "Hatchback"));
    bodyButtons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 50, WINDOW_H - 350), sf::Vector2f(170, 50), "Sedan"));
}

void App::createAdditionButtons()
{
    bodyButtons.clear();
    additionButtons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 50, WINDOW_H - 630), sf::Vector2f(186, 50), "Turn signal"));
    additionButtons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 50, WINDOW_H - 555), sf::Vector2f(186, 50), "Disks"));
    additionButtons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 50, WINDOW_H - 480), sf::Vector2f(186, 50), "Front and back"));
    additionButtons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 50, WINDOW_H - 405), sf::Vector2f(186, 50), "To create"));
}
void App::createMenuButtons() {
    menuButtons.push_back(Button(sf::Vector2f(WINDOW_W / 2 - 50, WINDOW_H - 630), sf::Vector2f(186, 50), "Menu"));
}

void App::update()
{

}
