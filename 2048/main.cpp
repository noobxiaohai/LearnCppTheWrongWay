#include <iostream>
#include <vector>
#include <map>
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime> // Header file needed to use time
#include "base.h"
using namespace std;

#define MOVE_UP_ORDER 1
#define MOVE_DOWN_ORDER 2
#define MOVE_RIGHT_ORDER 3
#define MOVE_LEFT_ORDER 4
map<char, int> inputOrders = { {'w', MOVE_UP_ORDER}, {'s', MOVE_DOWN_ORDER}, {'a', MOVE_LEFT_ORDER}, {'d', MOVE_RIGHT_ORDER} };

bool isValidInput(char x);

int main() {
    Game ourGame;

    char input;
    int orders;
    
    ourGame.gameGrid.generateNewBox();
    ourGame.gameGrid.generateNewBox();
    ourGame.gameGrid.showGrid();
    bool isBoxMoved;
    while(cin >> input){
        if(isValidInput(input) != true) {
            cout << "invalid input!" << endl;
            continue;
        };
        isBoxMoved = false;
        orders = inputOrders[input];
        if (orders == MOVE_RIGHT_ORDER) {
            for (int i = 0; i < GRID_HEIGHT_COUNT; i++) {
                for (int j = GRID_WIDTH_COUNT - 1; j >= 0; j--) {
                    bool thisMoved = ourGame.gameGrid.moveRight(j, i);
                    isBoxMoved = isBoxMoved || thisMoved;
                }
            }  
        }

        if (orders == MOVE_LEFT_ORDER) {
            for (int i = 0; i < GRID_HEIGHT_COUNT; i++) {
                for (int j = 0; j <= GRID_WIDTH_COUNT - 1; j++) {
                    bool thisMoved = ourGame.gameGrid.moveLeft(j, i);
                    isBoxMoved = isBoxMoved || thisMoved;
                }
            }
        }

        if (orders == MOVE_DOWN_ORDER) {
            for (int i = 0; i < GRID_WIDTH_COUNT; i++) {
                for (int j = GRID_HEIGHT_COUNT - 1; j >= 0; j--) {
                    bool thisMoved = ourGame.gameGrid.moveDown(i, j);
                    isBoxMoved = isBoxMoved || thisMoved;
                }
            }
        }

        if (orders == MOVE_UP_ORDER) {
            for (int i = 0; i < GRID_WIDTH_COUNT; i++) {
                for (int j = 0; j <= GRID_HEIGHT_COUNT - 1; j++) {
                    bool thisMoved = ourGame.gameGrid.moveUp(i, j);
                    isBoxMoved = isBoxMoved || thisMoved;
                }
            }
        }

        cout << "is box moved " << isBoxMoved << endl;
        if (isBoxMoved) {
            ourGame.gameGrid.generateNewBox();
        }

        ourGame.gameGrid.showGrid();
    }
}

bool isValidInput(char x){
    if(x=='w' || x=='a' || x=='s' || x=='d'){
        return true;
    }
    return false;
}
