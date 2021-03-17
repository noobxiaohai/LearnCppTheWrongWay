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
const map<char, int> inputOrders = {{'w', MOVE_UP_ORDER}, {'s', MOVE_LEFT_ORDER}, {'a', MOVE_RIGHT_ORDER}, {'d', MOVE_RIGHT_ORDER} };
bool isValidInput(char x);

int main() {

    Game ourGame;

    
    char input;
    int orders;

    cout << inputOrders['w'] << endl;
    int f_x = 0, f_y = 0, s_x = 1, s_y = 1;
    ourGame.gameGrid.setOneBox(f_x, f_y);
    ourGame.gameGrid.setOneBox(s_x, s_y);
    ourGame.showGrid();
    
    while(cin >> input){
        if(isValidInput(input) != true) {
            cout << "invalid input!" << endl;
            continue;
        };

        //orders = inputOrders[input];
        //if (orders == MOVE_RIGHT_ORDER) {
        //    for (int i = 0; i < GRID_WIDTH_COUNT; i++) {
        //        for (int j = 0; j < GRID_HEIGHT_COUNT; j++) {
        //            ourGame.gameGrid.moveRight(i, j);
        //        }
        //    }  
        //}

        ourGame.showGrid();
    }
}

bool isValidInput(char x){
    if(x=='w' || x=='a' || x=='s' || x=='d'){
        return true;
    }
    return false;
}
