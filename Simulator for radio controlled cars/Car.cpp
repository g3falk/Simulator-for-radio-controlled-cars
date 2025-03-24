#include "Car.h"

Car::Car(int input_x, int input_y, char input_dir){
    direction = parseDirection(input_dir);
    x = input_x;
    y = input_y;    
}

char Car::parseDirection(char input_dir) {
    input_dir = std::tolower(input_dir);
    if (input_dir == 'n' || input_dir == 's' || input_dir == 'e' || input_dir == 'w') {
        return input_dir;
    }
    else {
        throw std::invalid_argument("Car direction must be N/S/E/W");
    }
}

void Car::moveForward() {
    switch (direction) {
    case 'n': y += 1.0; break;
    case 'e': x += 1.0; break;
    case 's': y -= 1.0; break;
    case 'w': x -= 1.0; break;
    }
    
}

void Car::moveBackward() {
    switch (direction) {
    case 'n': y -= 1.0; break;
    case 'e': x -= 1.0; break;
    case 's': y += 1.0; break;
    case 'w': x += 1.0; break;
    }

}

void Car::rotateLeft() {
    switch (direction) {
    case 'n': direction = 'w'; break;
    case 'e': direction = 'n'; break;
    case 's': direction = 'e'; break;
    case 'w': direction = 's'; break;
    }   
}

void Car::rotateRight() {
    switch (direction) {
    case 'n': direction = 'e'; break;
    case 'e': direction = 's'; break;
    case 's': direction = 'w'; break;
    case 'w': direction = 'n'; break;
    }
    
}

int Car::getX(){
    return x;
}

int Car::getY(){
    return y;
}

char Car::getDirection(){
    return direction;
}
