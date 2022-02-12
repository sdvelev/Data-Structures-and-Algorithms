#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAX_NUMBER = 6007;

vector<int> graphMade[MAX_NUMBER];
int distArray[MAX_NUMBER];

void bfsShortestMade(int initialVertex) {
    queue<int> queueDistance;
    distArray[initialVertex] = 0;
    queueDistance.push(initialVertex);

    while (!queueDistance.empty()) {
        int topVertex = queueDistance.front();
        queueDistance.pop();

        for (auto neighbour : graphMade[topVertex]) {
            if (distArray[neighbour] > distArray[topVertex] + 1) {
                distArray[neighbour] = distArray[topVertex] + 1;
                queueDistance.push(neighbour);
            }
        }

    }
}

int main()
{
    int numberOfQueries;
    cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++) {
        int numberOfVertices;
        int numberOfEdges;

        cin >> numberOfVertices;
        cin >> numberOfEdges;

        int startVertex, endVertex;

        for (int i = 0; i <= numberOfVertices; i++) {
            graphMade[i].clear();
            distArray[i] = INT_MAX;
        }


        for (int i = 0; i < numberOfEdges; i++) {
            cin >> startVertex >> endVertex;
            graphMade[startVertex].push_back(endVertex);
            graphMade[endVertex].push_back(startVertex);
        }

        int initialIndex;
        cin >> initialIndex;

        bfsShortestMade(initialIndex);

        for (int i = 1; i <= numberOfVertices; i++) {
            if (distArray[i] != 0) {
                if (distArray[i] != INT_MAX) {
                    cout << distArray[i] * 6 << " ";
                }
                else {
                    cout << "-1 ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
