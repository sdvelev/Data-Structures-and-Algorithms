#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<set>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NUMBER_OF_VERTICES = 1000007;

vector<int> graphMade[MAX_NUMBER_OF_VERTICES];
int degreeArray[MAX_NUMBER_OF_VERTICES];
queue<int> foundLeavesQueue;

int numberOfVertices;
set<int> answerMinimumDepthSet;

int main()
{
    cin >> numberOfVertices;

    int startVertex;
    int finishVertex;

    for (int i = 1; i < numberOfVertices; i++) {
        cin >> startVertex;
        cin >> finishVertex;

        graphMade[startVertex].push_back(finishVertex);
        graphMade[finishVertex].push_back(startVertex);

        ++degreeArray[startVertex];
        ++degreeArray[finishVertex];
    }
    
    for (int i = 0; i < numberOfVertices; i++) {
        if (degreeArray[i] == 1) {
            foundLeavesQueue.push(i);
        }
    }

    int leftVertices = numberOfVertices;
    
    while (foundLeavesQueue.size() && leftVertices > 2) {
        int numberOfLeaves = foundLeavesQueue.size();

        for (int i = 0; i < numberOfLeaves; i++) {
            int currentLeaf = foundLeavesQueue.front();
            foundLeavesQueue.pop();
            --degreeArray[currentLeaf];
            --leftVertices;

            for (auto neighbour : graphMade[currentLeaf]) {
                --degreeArray[neighbour];
                if (degreeArray[neighbour] == 1) {
                    foundLeavesQueue.push(neighbour);
                }
            }
        }
    }

    while (foundLeavesQueue.size()) {
        int currentLeaf = foundLeavesQueue.front();
        foundLeavesQueue.pop();
        answerMinimumDepthSet.insert(currentLeaf);
    }

    for (auto element : answerMinimumDepthSet) {
        cout << element << " ";
    }
    return 0;
}
