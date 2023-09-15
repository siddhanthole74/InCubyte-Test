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
    LunarCraft(int x, int y, int z, char initialDirection) {
        positionX = x;
        positionY = y;
        positionZ = z;
        direction = initialDirection;
    }

    void moveForward() 
    {
        if (direction == 'N') {
            positionY++;
        } 
        else if (direction == 'S') {
            positionY--;
        } 
        else if (direction == 'E') {
            positionX++;
        } 
        else if (direction == 'W') {
            positionX--;
        } 
        else if (direction == 'U') {
            positionZ++;
        } 
        else if (direction == 'D') {
            positionZ--;
        }
    }

    void moveBackward() 
    {
        // Implement backward movement similarly to forward movement
        if (direction == 'N') 
        {
        positionY--; // Reverse the Y coordinate change
        } 
        else if (direction == 'S') 
        {
        positionY++; // Reverse the Y coordinate change
        } 
        else if (direction == 'E') 
        {
        positionX--; // Reverse the X coordinate change
        } 
        else if (direction == 'W') 
        {
        positionX++; // Reverse the X coordinate change
        } 
        else if (direction == 'U') 
        {
        positionZ--; // Reverse the Z coordinate change
        } 
        else if (direction == 'D') 
        {
        positionZ++; // Reverse the Z coordinate change
        }
    }

    void rotateLeft() 
    {
        // Implement left rotation
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

    void rotateRight() {
        // Implement right rotation
    }

    void rotateUp() {
        // Implement upward angle adjustment
    }

    void rotateDown() {
        // Implement downward angle adjustment
    }

    tuple<int, int, int, char> getCurrentState()
    {
        return make_tuple(positionX, positionY, positionZ, direction);
    }


};

int main()
{
    LunarCraft craft(0, 0, 0, 'N');  // Initialize with starting position and direction

    vector<char> commands = {'f', 'r', 'u', 'b', 'l','d'};

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
    return 0;
}
