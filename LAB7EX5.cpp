#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class VacuumRobot {
private:
    string brand;
    string productCode;
    int batteryPercentage;
    int x, y;       // Current position of the robot
    char direction; // Current direction: N, S, E, W
    char room[5][5]; // 5x5 room layout

public:
    VacuumRobot(string b, string p) {
        brand = b;
        productCode = p;
        batteryPercentage = 100;
        x = 2; // Starting position (center of the room)
        y = 2;
        direction = 'N'; // Initial direction: North
        initializeRoom();
    }

    void initializeRoom() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                room[i][j] = '.'; // Clean space
            }
        }
        room[x][y] = '^'; // Robot starts facing North
    }

    void printRoom() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << room[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "Battery: " << batteryPercentage << "%" << endl;
        cout << endl;
    }

    void turnLeft() {
        if (direction == 'N') direction = 'W';
        else if (direction == 'W') direction = 'S';
        else if (direction == 'S') direction = 'E';
        else if (direction == 'E') direction = 'N';
        room[x][y] = getDirectionSymbol();
    }

    void turnRight() {
        if (direction == 'N') direction = 'E';
        else if (direction == 'E') direction = 'S';
        else if (direction == 'S') direction = 'W';
        else if (direction == 'W') direction = 'N';
        room[x][y] = getDirectionSymbol();
    }

    char getDirectionSymbol() {
        switch (direction) {
            case 'N': return '^';
            case 'S': return 'v';
            case 'E': return '>';
            case 'W': return '<';
            default: return '?';
        }
    }

    void moveForward() {
        room[x][y] = '*'; // Clean the current space
        if (direction == 'N' && x > 0) x--;
        else if (direction == 'S' && x < 4) x++;
        else if (direction == 'E' && y < 4) y++;
        else if (direction == 'W' && y > 0) y--;
        room[x][y] = getDirectionSymbol();
        batteryPercentage -= 5;
    }

    void moveBackward() {
        room[x][y] = '*'; // Clean the current space
        if (direction == 'N' && x < 4) x++;
        else if (direction == 'S' && x > 0) x--;
        else if (direction == 'E' && y > 0) y--;
        else if (direction == 'W' && y < 4) y++;
        room[x][y] = getDirectionSymbol();
        batteryPercentage -= 5;
    }

    void autoMove() {
        while (batteryPercentage > 5) {
            int prevX = x, prevY = y;
            moveForward();
            if (x == prevX && y == prevY) { // Obstacle detected
                turnRight();
                moveForward();
                if (x == prevX && y == prevY) { // Right is blocked
                    turnLeft();
                    turnLeft();
                    moveForward();
                }
            }
            printRoom();
            checkBatteryStatus();
        }
        cout << "Battery depleted. Robot stopped." << endl;
    }

    void checkBatteryStatus() {
        if (batteryPercentage == 15 || batteryPercentage == 10 || batteryPercentage == 5) {
            cout << "Warning: Battery low at " << batteryPercentage << "%!" << endl;
        }
    }
};

int main() {
    srand(time(0));
    VacuumRobot robot("CleanMaster", "CMX2024");
    robot.printRoom();
    robot.autoMove();
    return 0;
}
