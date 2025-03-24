#pragma once
#include <iostream>
#include <stdexcept>
class Car
{
private:
    int x;
    int y;
    char direction;

public:
    Car(int startX, int startY, char startDir);

    char parseDirection(char direction);

    void moveForward();

    void moveBackward();

    void rotateLeft();

    void rotateRight();

    int getX();

    int getY();

    char getDirection();

};
