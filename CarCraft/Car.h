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
    std::string path;
    sf::RenderWindow* mainWindow;
    std::string savePath;
    std::string getPath(bool body);
    Car() : turnSignal(false), disks(false), frontAndBack(false), bodyFlag(false) {}
};
