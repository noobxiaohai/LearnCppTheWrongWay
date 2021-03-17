#pragma once
#include <iostream>
#include <vector>

using namespace std;

#define GRID_WIDTH_COUNT 4
#define GRID_HEIGHT_COUNT 4
#define INIT_BOX_VALUE 2

class Box
{
public:
	int xPos, yPos;
	int value = 0;
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
    
    bool setOneBox(int x, int y){
        if(gridVector[x][y].value !=0) return false;
        
        gridVector[x][y].value = INIT_BOX_VALUE;
        cout << "test set" << gridVector[x][y].value << endl;
        return true;
    }

    bool moveRight(int x, int y){
        Box* movedBox = &gridVector[x][y]; //todo: use pointer is better

        if ((*movedBox).value == 0) {
            return false;
        }

        int p = x;
        while (p + 1 != GRID_WIDTH_COUNT) {
            if (gridVector[p + 1][y].value == 0) {
                gridVector[p + 1][y].value = gridVector[p][y].value;
                gridVector[p][y].value = 0;
            }

            // todo: resolve that next box can be combined

            p++;
        }

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

    Game(): gameGrid(){};
	int showGrid()
	{
		for (auto lineBoxes : gameGrid.gridVector) {
			cout << "| ";
			for (auto box: lineBoxes) {
				cout << box.value << " | ";
			}
			cout << endl;
		}

		return 1;
	}

};
//
