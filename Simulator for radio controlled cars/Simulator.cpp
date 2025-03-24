#include "Simulator.h"

using namespace std;

Simulator::Simulator(){
    commands = "";
}

void Simulator::run() {
    try{
        //Setup Room where height and width must be postive integers
        cout << "Enter Room Height and Width: ";
        int width, length;
        cin >> width >> length;
        Room room(width, length);

        //Setup Car where the car postions needs to be inside the room and a valid direction
        cout << "Enter starting Position (X Y) and Direction (N/S/E/W): ";
        int startX, startY;
        char direction;
        cin >> startX >> startY >> direction;
        if (!room.isPositionValid(startX, startY)) {
            throw invalid_argument("Car starts outside the room.");
        }
        Car car(startX, startY, direction);

        //take users commands and runs coresponding function call, the commands must be f/b/l/r
        cout << "Enter starting commands: ";
        cin >> commands;        
        for (char cmd : commands) {
            switch (tolower(cmd)) {
            case 'f': car.moveForward(); break;
            case 'b': car.moveBackward(); break;
            case 'l': car.rotateLeft(); break;
            case 'r': car.rotateRight(); break;
            default:
                throw invalid_argument("Invalid command. Use F/B/L/R.");
            }

            //checking if the car hit a wall
            if (!room.isPositionValid(car.getX(), car.getY())) {
                cout << "Unsuccessful: Car hit the wall at (" << car.getX() << ", " << car.getY() << ").\n";
                return;
            }
        }

        //The car did not crash and prints out the position of the car and its direction
        cout << "Successful: Final position (" << car.getX() << ", " << car.getY() << ") " << car.getDirection() << "\n";

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}