#pragma once
#include "Car.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

class Simulator {
private:
    bool validateRoomInput(std::string& input);
    bool validateCarInput(std::string& input);
    bool validateCommandsInput(std::string& input);
public:
    Simulator();
    void run();
};
