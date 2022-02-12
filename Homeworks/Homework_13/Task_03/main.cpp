#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NUMBER = 100007;
map<int, int> degreeOfVertices;
int numberOfVertices, numberOfEdges;
vector<string> answerVector;

map <int, vector<int>> graphMade;
map<int, bool> visited;

set<int> addedVertices;

void depthFirstSearchMade(int startVertex) {

    visited[startVertex] = 1;

    for (auto neighbour : graphMade[startVertex]) {
        if (!visited.count(neighbour)) {
            depthFirstSearchMade(neighbour);
        }
    }
}

bool isConnected() {
    int counterOfComponents = 0;
    for (auto vertex : addedVertices) {
        if (!visited.count(vertex)) {
            depthFirstSearchMade(vertex);
            ++counterOfComponents;
        }
        if (counterOfComponents > 1) {
            return false;
        }
    }
    return true;
}

int main()
{
    int numberOfQueries;
    cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++) {
        cin >> numberOfVertices;
        cin >> numberOfEdges;

        int startVertice;
        int finishVertice;
        int numberOfVerticesWithOddDegree = 0;

        visited.clear();
        graphMade.clear();
        degreeOfVertices.clear();
        addedVertices.clear();

        for (int j = 0; j < numberOfEdges; j++) {
            cin >> startVertice;
            cin >> finishVertice;
            graphMade[startVertice].push_back(finishVertice);
            graphMade[finishVertice].push_back(startVertice);
            addedVertices.insert(startVertice);
            addedVertices.insert(finishVertice);
            degreeOfVertices[startVertice]++;
            degreeOfVertices[finishVertice]++;
        }


        for (auto vertex : degreeOfVertices) {
            if (vertex.second % 2 != 0) {
                ++numberOfVerticesWithOddDegree;
            }
        }

        if (!isConnected() || addedVertices.size() < numberOfVertices) {
            answerVector.push_back("none");
            continue;
        }

        if (numberOfVerticesWithOddDegree == 0) {
            answerVector.push_back("ecycle");
        }
        else if (numberOfVerticesWithOddDegree == 2) {
            answerVector.push_back("epath");
        }
        else {
            answerVector.push_back("none");
        }
    }

    int size = answerVector.size();

    for (int i = 0; i < size; i++) {
        cout << answerVector[i] << endl;
    }
    return 0;
}
