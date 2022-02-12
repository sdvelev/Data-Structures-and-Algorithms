#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_NUMBER_OF_VERTICES = 100007;
vector<int> graphMade[MAX_NUMBER_OF_VERTICES];
bool visited[MAX_NUMBER_OF_VERTICES];
vector<int> answer;

void dfs(int vertex){
    visited[vertex] = 1;

    for (auto neighbour : graphMade[vertex]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}

void solve() {

    for (int i = 0; i < MAX_NUMBER_OF_VERTICES; i++) {
        visited[i] = 0;
        graphMade[i].clear();
    }

    int numberOfVertices;
    cin >> numberOfVertices;

    int numberOfEdges;
    cin >> numberOfEdges;

    int fromVertex;
    int toVertex;

    for (int i = 0; i < numberOfEdges; i++) {
        cin >> fromVertex >> toVertex;
        graphMade[fromVertex].push_back(toVertex);
        graphMade[toVertex].push_back(fromVertex);
    }

    int counter = 0;

    for (int i = 0; i < numberOfVertices; i++) {
        if (!visited[i]) {
            dfs(i);
            counter++;
        }
    }

    answer.push_back(counter);
}

int main()
{

    int numberOfQueries;
    cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++) {
        solve();
    }

    int size = answer.size();
    for (int i = 0; i < size; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
