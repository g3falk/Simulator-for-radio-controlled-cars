#include "Room.h"

Room::Room(int inputwidth, int inputheight){
    if (inputwidth <= 0 || inputheight <= 0) {
        throw std::invalid_argument("Room dimensions must be positive integers.");
    }
    width = inputwidth;
    height = inputheight;
}

bool Room::isPositionValid(int x, int y){

    if (x >= 0 && x < width && y >= 0 && y < height) {
        return true;
    }        
    else {
        return false;
    }
}