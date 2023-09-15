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
    LunarCraft(int x, int y, int z, char initialDirection) 
    {
        positionX = x;
        positionY = y;
        positionZ = z;
        direction = initialDirection;
    }
    // implementation of  move forword function
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
            case 'U':
                direction = 'D';  // Update for Up and Down rotations
                break;
            case 'D':
                direction = 'U';  // Update for Up and Down rotations
                break;
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
            case 'U':
                direction = 'D';  // Update for Up and Down rotations
                break;
            case 'D':
                direction = 'U';  // Update for Up and Down rotations
                break;
        }
    }
    // implementation of rotate up function
    void rotateUp() 
    {
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            direction = 'U';
        }
        // No change for Up or Down in other cases
    }
    // implemetation of rotate down function
    void rotateDown() 
    {
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            direction = 'D';
        }
        // No change for Up or Down in other cases
    }

    tuple<int, int, int, char> getCurrentState() 
    {
        return std::make_tuple(positionX, positionY, positionZ, direction);
    }
};

int main() {
    LunarCraft craft(0, 0, 0, 'N');  // Initialize with starting position and direction

    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    for (char command : commands) 
    {
        if (command == 'f') 
        {
            craft.moveForward();
        } 
        else if (command == 'b') 
        {
            craft.moveBackward();
        } 
        else if (command == 'r') 
        {
            craft.rotateRight();
        } 
        else if (command == 'l') 
        {
            craft.rotateLeft();
        } 
        else if (command == 'u') 
        {
            craft.rotateUp();
        } 
        else if (command == 'd') 
        {
            craft.rotateDown();
        }
    }

    tuple<int, int, int, char> finalState = craft.getCurrentState();
    int finalX, finalY, finalZ;
    char finalDirection;
    tie(finalX, finalY, finalZ, finalDirection) = finalState;

    cout << "Final Position: (" << finalX << ", " << finalY << ", " << finalZ << ")\n";
    cout << "Final Direction: " << finalDirection << "\n";

    return 0;
}
