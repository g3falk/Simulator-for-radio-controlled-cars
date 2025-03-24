#include "Simulator.h"

Simulator::Simulator(){
    commands = "";
}

void Simulator::run() {
    try{
        //Setup Room where height and width must be postive integers
        std::cout << "Enter Room Height and Width: ";
        int width, length;
        std::cin >> width >> length;
        Room room(width, length);

        //Setup Car where the car postions needs to be inside the room and a valid direction
        std::cout << "Enter starting Position (X Y) and Direction (N/S/E/W): ";
        int startX, startY;
        char direction;
        std::cin >> startX >> startY >> direction;
        if (!room.isPositionValid(startX, startY)) {
            throw std::invalid_argument("Car starts outside the room.");
        }
        Car car(startX, startY, direction);

        //take users commands and runs coresponding function call, the commands must be f/b/l/r
        std::cout << "Enter starting commands: ";
        std::cin >> commands;        
        for (char cmd : commands) {
            switch (cmd) {
            case 'f': car.moveForward(); break;
            case 'b': car.moveBackward(); break;
            case 'l': car.rotateLeft(); break;
            case 'r': car.rotateRight(); break;
            default:
                throw std::invalid_argument("Invalid command. Use F/B/L/R.");
            }

            //checking if the car hit a wall
            if (!room.isPositionValid(car.getX(), car.getY())) {
                std::cout << "Unsuccessful: Car hit the wall at (" << car.getX() << ", " << car.getY() << ").\n";
                return;
            }
        }

        //The car did not crash and prints out the position of the car and its direction
        std::cout << "Successful: Final position ("
            << car.getX() << ", "
            << car.getY() << ") "
            << car.getDirection() << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}