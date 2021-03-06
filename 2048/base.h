#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

#define GRID_WIDTH_COUNT 4
#define GRID_HEIGHT_COUNT 4
#define INIT_VALUE_SCALE 10
#define INIT_BOX_VALUE pow(2, INIT_VALUE_SCALE)

int randomInt(int length);

class Box
{
public:
	int xPos, yPos;
	int value = 0;
    bool isCombined = false;
    Box(int x, int y);
};

Box::Box(int x, int y){
    xPos = x;
    yPos = y;
}
////
class Grid
{
public:
	vector<vector<Box> > gridVector;
    Grid();
    vector<vector<int>> emptyBoxes;

    
    bool setOneBox(int x, int y){
        if(gridVector[y][x].value !=0) return false;
        gridVector[y][x].value = INIT_BOX_VALUE;
        return true;
    }


    int showGrid(){
        for (auto lineBoxes : gridVector) {
            cout << "| ";
            for (auto box : lineBoxes) {
                cout << setw(4) << box.value << " | ";
            }
            cout << endl;
        }

        return 1;
    }

    bool moveRight(int x, int y){
        Box* movedBox = &gridVector[y][x]; //todo: use pointer is better
        bool isMoved = false;
        if ((*movedBox).value == 0) {
            return isMoved;
        }
        
        int p = x;
        while (p + 1 != GRID_WIDTH_COUNT) {
            Box* movingBox = &gridVector[y][p];
            Box* stillBox = &gridVector[y][p + 1];

            if (!moveBoxes(movingBox, stillBox)) {
                //break;
                isMoved = false;
                return isMoved;
            }
            isMoved = true;
            p++;
        }
        return isMoved;
    }

    bool moveLeft(int x, int y) {
        Box* movedBox = &gridVector[y][x]; //todo: use pointer is better
        bool isMoved = false;
        if ((*movedBox).value == 0) {
            return isMoved;
        }

        int p = x;
        while (p - 1 >= 0) {
            Box* movingBox = &gridVector[y][p];
            Box* stillBox = &gridVector[y][p - 1];

            if (!moveBoxes(movingBox, stillBox)) {
                isMoved = false;
                return isMoved;
            }
            isMoved = true;
            p--;
        }
        return isMoved;
    
    }

    bool moveDown(int x, int y) {
        Box* movedBox = &gridVector[y][x];
        bool isMoved = false;
        if ((*movedBox).value == 0) {
            return isMoved;
        }

        int p = y;
        while (p + 1 != GRID_WIDTH_COUNT) {
            Box* movingBox = &gridVector[p][x];
            Box* stillBox = &gridVector[p + 1][x];

            if (!moveBoxes(movingBox, stillBox)) {
                isMoved = false;
                return isMoved;
            }
            isMoved = true;

            p++;
        }
        return isMoved;

    }

    bool moveUp(int x, int y) {
        Box* movedBox = &gridVector[y][x];
        bool isMoved = false;
        if ((*movedBox).value == 0) {
            return isMoved;
        }

        int p = y;
        while (p - 1 >= 0) {
            Box* movingBox = &gridVector[p][x];
            Box* stillBox = &gridVector[p - 1][x];

            if (!moveBoxes(movingBox, stillBox)) {
                isMoved = false;
                return isMoved;
            }
            isMoved = true;
            p--;
        }
        return isMoved;
    }

    bool moveBoxes(Box* movingBox, Box* stillBox) {
        if ((*movingBox).value == 0) {
            cout << "moveBoxes function error!!!!" << (*movingBox).xPos << ' ' << (*movingBox).yPos << endl;
            return false;
        }

        if ((*stillBox).value == 0) {
            (*stillBox).value = (*movingBox).value;
            (*movingBox).value = 0;
            return true;
        }
    
        if ((*stillBox).value == (*movingBox).value) {
            (*stillBox).value = (*stillBox).value + (*movingBox).value;
            (*movingBox).value = 0;
            return true;
        }
    
        return false;
    }

    void getEmptyBoxes(void) {
        emptyBoxes.clear();
        for (auto lineBoxes : gridVector) {
            for (auto box : lineBoxes) {
                if (box.value == 0) {
                    emptyBoxes.push_back({ box.xPos, box.yPos });
                }
            }
        }
    }

    bool generateNewBox() {
        getEmptyBoxes();
        if (emptyBoxes.empty()) return false;

        int length = emptyBoxes.size();
        
        int randomIdx = randomInt(length);
        int newBoxX = emptyBoxes[randomIdx][0];
        int newBoxY = emptyBoxes[randomIdx][1];
        setOneBox(newBoxX, newBoxY);
        cout << "generated box pos is: " << newBoxX << '|' << newBoxY << endl;
        return true;
    }


};

Grid::Grid(void){
    {
        int i, j;
        for ( i = 0; i < GRID_WIDTH_COUNT; i++) {
            vector<Box> row;
            for (j = 0; j < GRID_HEIGHT_COUNT; j++) {
                row.push_back(Box(i, j));
            }
            gridVector.push_back(row);
        }
    }
}
//

class Game
{
public:
	int score;
	Grid gameGrid;
};
//

int randomInt(int length) {
    srand((unsigned)time(NULL));
    return (rand() % (length));
}