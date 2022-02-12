#include <cmath>
#include <cstdio>
#include <vector>
#include<unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

enum State {
    Unvisited = -1,
    CurrentlyVisit = 0,
    Visited = 1
};

const int MAX_NUMBER = 1000000;
unordered_map<int, vector<int>> graphMade;
unordered_map<int, State> visitedVertices;
vector<int> answer;

bool isSameVersion(int vertex) {
    visitedVertices[vertex] = (State) 0;

    for (auto neighbour : graphMade[vertex]) {
        if (visitedVertices[neighbour] == (State)0 || 
            (visitedVertices[neighbour] == (State)-1 && isSameVersion(neighbour))) {
            return true;
        }
    }

    visitedVertices[vertex] = (State)1;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numberOfQueries;
    cin >> numberOfQueries;

    int numberOfEdges;
    int startVertex, endVertex;

    int maxVertex = 0;

    for (int i = 0; i < numberOfQueries; i++) {
        
        cin >> numberOfEdges;

        for (int j = 0; j < numberOfEdges; j++) {
            cin >> startVertex;
            cin >> endVertex;
            
            if(startVertex > maxVertex){
                maxVertex = startVertex;
            }
            
            if(endVertex > maxVertex){
                maxVertex = endVertex;
            }

            graphMade[startVertex].push_back(endVertex);
        }

        for (int i = 0; i < maxVertex + 1; i++) {
            visitedVertices[i] = (State)-1;
        }

        bool flag = false;

        for (int i = 0; i < maxVertex + 1; i++) {
            if (visitedVertices[i] == (State)-1) {
                if (isSameVersion(i)) {
                    answer.push_back(1);
                    flag = true;
                    break;
                }
            }
        }

        if (flag == false) {
            answer.push_back(0);
        }
        visitedVertices.clear();
        graphMade.clear();
    }

    for (auto ans : answer) {
        printf("%d ", ans);
    }

    return 0;
}
