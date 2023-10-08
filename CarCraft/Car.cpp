#include "Car.h"

std::string Car::getPath(bool body)
{
    std::string path;
    if (body == false) { //Hatchback
        if (turnSignal == true && disks == true && frontAndBack == true) {
            path = "Hatchback\\ttt.psd";
        }
        else if (turnSignal == false && disks == false && frontAndBack == false) {
            path = "Hatchback\\fff.psd";
        }
        else if (turnSignal == false && disks == false && frontAndBack == true) {
            path = "Hatchback\\fft.psd";
        }
        else if (turnSignal == false && disks == true && frontAndBack == true) {
            path = "Hatchback\\ftt.psd";
        }
        else if (turnSignal == true && disks == false && frontAndBack == true) {
            path = "Hatchback\\tft.psd";
        }
        else if (turnSignal == true && disks == false && frontAndBack == false) {
            path = "Hatchback\\tff.psd";
        }
        else if (turnSignal == true && disks == true && frontAndBack == false) {
            path = "Hatchback\\ttf.psd";
        }
        else if (turnSignal == false && disks == true && frontAndBack == false) {
            path = "Hatchback\\ftf.psd";
        }
    }
    else if (body == true) {// Sedan
        if (turnSignal == true && disks == true && frontAndBack == true) {
            path = "Sedan\\ttt.psd";
        }
        else if (turnSignal == false && disks == false && frontAndBack == false) {
            path = "Sedan\\fff.psd";
        }
        else if (turnSignal == false && disks == false && frontAndBack == true) {
            path = "Sedan\\fft.psd";
        }
        else if (turnSignal == false && disks == true && frontAndBack == true) {
            path = "Sedan\\ftt.psd";
        }
        else if (turnSignal == true && disks == false && frontAndBack == true) {
            path = "Sedan\\tft.psd";
        }
        else if (turnSignal == true && disks == false && frontAndBack == false) {
            path = "Sedan\\tff.psd";
        }
        else if (turnSignal == true && disks == true && frontAndBack == false) {
            path = "Sedan\\ttf.psd";
        }
        else if (turnSignal == false && disks == true && frontAndBack == false) {
            path = "Sedan\\ftf.psd";
        }
    }
    savePath = path;
    return path;
}
