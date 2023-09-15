/**
 * @file Solution.cpp
 * @author Siddhant Vijay Hole (you@domain.com)
 * @brief  Problem Statement : Chandrayaan 3 TDD Assessment
 * @version 0.1
 * @date 2023-09-15
 * @copyright Copyright (c) 2023
 */

#include<bits/stdc++.h>
using namespace std;

class LunarCraft {
private:
    int positionX;
    int positionY;
    int positionZ;
    char direction;

public:
    // parameterized Constructor
    LunarCraft(int x, int y, int z, char initialDirection)
    {
        positionX = x;
        positionY = y;
        positionZ = z;
        direction = initialDirection;
    }
    // implementation of moveforword function
    void moveForward() 
    {
        if (direction == 'N') 
        {
            positionY++;
        } 
        else if (direction == 'S') 
        {
            positionY--;
        } 
        else if (direction == 'E') 
        {
            positionX++;
        } 
        else if (direction == 'W') 
        {
            positionX--;
        } 
        else if (direction == 'U')
        {
            positionZ++;
        } 
        else if (direction == 'D') 
        {
            positionZ--;
        }
    }

    // implementation of movebackword function
    void moveBackward() 
    {
        if (direction == 'N') 
        {
            positionY--;
        } 
        else if (direction == 'S') 
        {
            positionY++;
        } 
        else if (direction == 'E') 
        {
            positionX--;
        } 
        else if (direction == 'W') 
        {
            positionX++;
        } 
        else if (direction == 'U') 
        {
            positionZ--;
        } 
        else if (direction == 'D') 
        {
            positionZ++;
        }
    }

    // implementation of rotate left function
    void rotateLeft() 
    {
        switch (direction) 
        {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
            // Up and Down directions remain the same during left/right rotation
        }
    }

    // implementation of rotate right function
    void rotateRight() 
    {
        switch (direction) 
        {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
            // Up and Down directions remain the same during left/right rotation
        }
    }

    // implementation of rotate up function
    void rotateUp() 
    {
        if (direction == 'N' || direction == 'S') 
        {
            direction = 'U';
        } 
        else if (direction == 'D' || direction == 'U') 
        {
            // No change for Up or Down
        } 
        else if (direction == 'E') 
        {
            direction = 'R'; // Right
        } 
        else if (direction == 'W') 
        {
            direction = 'L'; // Left
        }
    }

    // implementation of rotate down function
    void rotateDown() 
    {
        if (direction == 'N' || direction == 'S') 
        {
            direction = 'D';
        } 
        else if (direction == 'D' || direction == 'U') 
        {
            // No change for Up or Down
        } 
        else if (direction == 'E') 
        {
            direction = 'R'; // Right
        } 
        else if (direction == 'W') 
        {
            direction = 'L'; // Left
        }
    }

    tuple<int, int, int, char> getCurrentState() 
    {
        return std::make_tuple(positionX, positionY, positionZ, direction);
    }
};

int main() {
    vector<tuple<string,vector<char>,tuple<int, int, int, char>>> testCases =
    {
        {"Test 1: Initial Position (0, 0, 0) - Direction N",
         {'f', 'r', 'u', 'b', 'l'},
         {0, 0, 0, 'N'}
         },
        // Add more test cases as needed
    };

    for (const auto& testCase : testCases) 
    {
        string testName = std::get<0>(testCase);
        vector<char> commands = std::get<1>(testCase);
        tuple<int, int, int, char> expectedState = std::get<2>(testCase);

        LunarCraft chandrayaan(get<0>(expectedState),get<1>(expectedState), get<2>(expectedState), std::get<3>(expectedState));

        for (char command : commands) {
            switch (command) {
                case 'f':
                    chandrayaan.moveForward();
                    break;
                case 'b':
                    chandrayaan.moveBackward();
                    break;
                case 'r':
                    chandrayaan.rotateRight();
                    break;
                case 'l':
                    chandrayaan.rotateLeft();
                    break;
                case 'u':
                    chandrayaan.rotateUp();
                    break;
                case 'd':
                    chandrayaan.rotateDown();
                    break;
                default:
                    std::cout << "Invalid command: " << command << std::endl;
                    break;
            }
        }

        tuple<int, int, int, char> finalState = chandrayaan.getCurrentState();

        bool testPassed = finalState == expectedState;

        cout << testName << " - " << (testPassed ? "Passed" : "Failed") <<endl;
        if (!testPassed) {
            cout << "Expected: Position (" << get<0>(expectedState) << ", " <<get<1>(expectedState) << ", " <<get<2>(expectedState) << ") Direction: " <<get<3>(expectedState) <<endl;
            cout << "Actual: Position (" <<get<0>(finalState) << ", " <<get<1>(finalState) << ", " <<get<2>(finalState) << ") Direction: " <<get<3>(finalState) <<endl;
        }

        cout <<endl;
    }

    return 0;
}
