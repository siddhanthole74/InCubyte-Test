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

    void moveForward() {
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

    void moveBackward() {
        // Implement backward movement similarly to forward movement
    }

    void rotateLeft() {
        // Implement left rotation
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
    return 0;
}
