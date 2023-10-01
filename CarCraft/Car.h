#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"
class Car {
public:

    bool turnSignal;
    bool disks;
    bool frontAndBack;
    bool bodyFlag;
    bool flag;
    std::string path;
    sf::RenderWindow* mainWindow;
    Car() : turnSignal(false), disks(false), frontAndBack(false), flag(false) {};
    std::string getPath(bool body);
private:
    std::vector<Car> save;
};

