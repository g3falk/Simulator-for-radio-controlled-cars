#pragma once
#include <stdexcept>

class Room {
private:
    int width;
    int height;

public:
    Room(int width, int length);

    bool isPositionValid(int x, int y);
};

