#include "Simulator.h"

using namespace std;
Simulator::Simulator(){
}

bool Simulator::validateRoomInput(string& input) {
    regex pattern(R"(^\d+\s\d+$)");
    return regex_match(input, pattern);
}

bool Simulator::validateCarInput(string& input) {
    regex pattern(R"(^\d+\s+\d+\s+[NSEWnsew]$)");
    return regex_match(input, pattern);
}

bool Simulator::validateCommandsInput(string& input) {
    regex pattern(R"(^[FBRLfbrl]+$)");
    return regex_match(input, pattern);
}

void Simulator::run() {
    try {
        //Setup Room where height and width must be postive integers
        string line;
        istringstream iss;
        int width, height;
        cout << "Enter Room Height and Width: ";
        getline(cin, line);
        if (!validateRoomInput(line)) {
            throw invalid_argument("Invalid Input!");
        }
        iss.clear();
        iss.str(line);
        iss >> width >> height;
        Room room(width, height);


        //Setup Car where the car postions needs to be inside the room and a valid direction
        int startX, startY;
        char direction;
        cout << "Enter starting position (X Y) and Direction (N/S/E/W): ";
        getline(cin, line);
        if (!validateCarInput(line)) {
            throw invalid_argument("Invalid Input!");
        }
        iss.clear();
        iss.str(line);
        iss >> startX >> startY >> direction;
        if (!room.isPositionValid(startX, startY)) {
            throw invalid_argument("Car starts outside the room.");
        }
        Car car(startX, startY, direction);


        //take users commands and runs coresponding function call, the commands must be f/b/l/r
        string commands;
        cout << "Enter commands tha the car should execute: ";
        getline(cin, line);
        if (validateCommandsInput(line)) {
            commands = line;
            for (char& cmd : commands) {
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
            cout << "Successful: Final position (" << car.getX() << ", " << car.getY() << ") Car Direction: " << (char)toupper(car.getDirection()) << "\n";
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}