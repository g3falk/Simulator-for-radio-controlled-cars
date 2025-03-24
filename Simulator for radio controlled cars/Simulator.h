#pragma once
#include "Car.h"
#include "Room.h"
#include <iostream>

class Simulator {private:
private:
    std::string commands;
public:
    Simulator();
    void run();
};
