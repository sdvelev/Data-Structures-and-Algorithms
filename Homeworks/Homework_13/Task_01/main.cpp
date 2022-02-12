#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 25;

char mazeArray[MAX_SIZE + 7][MAX_SIZE + 7];
int visitedArray[MAX_SIZE + 7][MAX_SIZE + 7];
vector<vector<int>> directionsVector = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int numberOfRows;
int numberOfColumns;
int numberOfPassableDoors;
int numberOfWays = 0;

bool isValidCell(int currentRow, int currentColumn) {
    if (currentRow >= 0 && currentColumn >= 0 && currentRow < numberOfRows && currentColumn < numberOfColumns
        && mazeArray[currentRow][currentColumn] != 'x' && visitedArray[currentRow][currentColumn] == 0) {
        return true;
    }
    return false;
}

void depthFirstSearchMade(int currentRow, int currentColumn, int numberOfPassedDoors) {
    visitedArray[currentRow][currentColumn] = 1;

    if (mazeArray[currentRow][currentColumn] == 'e' && numberOfPassedDoors == numberOfPassableDoors) {
        ++numberOfWays;
    }

    for (auto direction : directionsVector) {
        int directionRowIndex = direction[0];
        int directionColumnIndex = direction[1];

        int neighbourRow = currentRow + directionRowIndex;
        int neighbourColumn = currentColumn + directionColumnIndex;

        if (!isValidCell(neighbourRow, neighbourColumn)) {
            continue;
        }

        visitedArray[neighbourRow][neighbourColumn] = 1;
        
        depthFirstSearchMade(neighbourRow, neighbourColumn, numberOfPassedDoors + 1);
        
        visitedArray[neighbourRow][neighbourColumn] = 0;
    }

}

int main()
{
    cin >> numberOfRows;
    cin >> numberOfColumns;

    for (int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            cin >> mazeArray[i][j];
        }
    }

    numberOfPassableDoors = numberOfRows * numberOfColumns;
    pair<int, int> initialPosition;

    for (int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            if (mazeArray[i][j] == 'x') {
                --numberOfPassableDoors;
            }
            else if (mazeArray[i][j] == 's') {
                initialPosition.first = i;
                initialPosition.second = j;
            }
        }
    }
    
    visitedArray[initialPosition.first][initialPosition.second] = 1;
    int numberOfPassedDoors = 1;
    depthFirstSearchMade(initialPosition.first, initialPosition.second, numberOfPassedDoors);
    cout << numberOfWays;
    return 0;
}
