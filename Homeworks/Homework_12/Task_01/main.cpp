#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NUMBER_OF_VERTICES = 1007;
vector<pair<int, int>> edgeListMade;
int parentArrayMade[MAX_NUMBER_OF_VERTICES], depthArrayMade[MAX_NUMBER_OF_VERTICES];

vector<int> answerVector;

int findIfConnected(int vertex) {
    if (vertex == parentArrayMade[vertex]) {
        return vertex;
    }
    return parentArrayMade[vertex] = findIfConnected(parentArrayMade[vertex]);
}

void uniteDifferentComponents(int fromVertex, int toVertex) {
    int rootFromVertex = findIfConnected(fromVertex);
    int rootToVertex = findIfConnected(toVertex);

    if (depthArrayMade[rootFromVertex] > depthArrayMade[rootToVertex]) {
        parentArrayMade[rootToVertex] = rootFromVertex;
    }
    else {
        parentArrayMade[rootFromVertex] = rootToVertex;
    }

    if (depthArrayMade[rootFromVertex] == depthArrayMade[rootToVertex]) {
        depthArrayMade[rootToVertex]++;
    }
}

void areConnectedInformation(int fromVertex, int toVertex) {
    if (findIfConnected(fromVertex) != findIfConnected(toVertex)) {
        uniteDifferentComponents(fromVertex, toVertex);
    }
}

int areConnectedQuestion(int fromVertex, int toVertex) {
    if (findIfConnected(fromVertex) != findIfConnected(toVertex)) {
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{
    int numberOfVertices;
    int numberOfEdges;

    cin >> numberOfVertices;
    cin >> numberOfEdges;


    int fromVertex;
    int toVertex;

    for (int i = 0; i < numberOfEdges; i++) {
        cin >> fromVertex >> toVertex;
        edgeListMade.push_back({fromVertex, toVertex });
        edgeListMade.push_back({ toVertex, fromVertex });
    }

    for (int i = 0; i < numberOfVertices; i++) {
        parentArrayMade[i] = i;
        depthArrayMade[i] = 0;
    }

    int size = edgeListMade.size();
    for (int i = 0; i < size; i++)
    {
        areConnectedInformation(edgeListMade[i].first, edgeListMade[i].second);
    }

    int numberOfQueries;
    cin >> numberOfQueries;

    int queryType;

    for (int i = 0; i < numberOfQueries; i++) {
        cin >> queryType >> fromVertex >> toVertex;

        if (queryType == 1) {
            answerVector.push_back(areConnectedQuestion(fromVertex, toVertex));
        }
        else if (queryType == 2) {
            edgeListMade.push_back({fromVertex, toVertex});
            edgeListMade.push_back({toVertex, fromVertex});
            areConnectedInformation(fromVertex, toVertex);
            areConnectedInformation(toVertex, fromVertex);
        }
    }

    size = answerVector.size();
    for (int i = 0; i < size; i++) {
        cout << answerVector[i];
    }
    return 0;
}
