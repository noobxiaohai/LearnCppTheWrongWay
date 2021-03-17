#include <iostream>
#include <vector>
#include <map>
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime> // Header file needed to use time
#include "base.h"
using namespace std;

const map<char, int> inputOrders = {{'w', 0}, {'s', 1}, {'a', 2}, {'d', 3}, };
bool isValidInput(char x);

int main() {

    Game ourGame;

    
    char input;

    int f_x = 0, f_y = 0, s_x = 1, s_y = 1;
    ourGame.gameGrid.setOneBox(f_x, f_y);
    ourGame.gameGrid.setOneBox(s_x, s_y);
    ourGame.showGrid();
    
    while(cin >> input){
        if(isValidInput(input) != true) {
            cout << "invalid input!" << endl;
            continue;
        };
        ourGame.showGrid();
    }
}

bool isValidInput(char x){
    if(x=='w' || x=='a' || x=='s' || x=='d'){
        return true;
    }
    return false;
}
