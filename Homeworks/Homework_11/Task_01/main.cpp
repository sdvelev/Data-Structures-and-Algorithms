#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<climits>
#include <iostream>
#include <algorithm>

using namespace std;

const long long MAX_NUMBER_OF_VERTICES = 100001;
const long long MODULE = 1000000007;

vector<pair<long long, long long>> graphMade[MAX_NUMBER_OF_VERTICES];
pair<long long, long long> distanceArray[MAX_NUMBER_OF_VERTICES+1];

void dijkstraMade(long long startVertex) {
    for (long long i = 1; i <= MAX_NUMBER_OF_VERTICES; i++) {
        distanceArray[i].first = LONG_MAX;
        distanceArray[i].second = 0;
    }

    distanceArray[startVertex].first = 0;
    distanceArray[startVertex].second = 1;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> priorityQueueMade;
    priorityQueueMade.push({distanceArray[startVertex].first, startVertex});

    while (priorityQueueMade.size()) {
        pair<long long, long long> topPair = priorityQueueMade.top();
        priorityQueueMade.pop();
        long long topVertex = topPair.second;
        long long topPriceEdge = topPair.first;

        for (auto neighbour : graphMade[topVertex]) {
            long long neighbourVertex = neighbour.first;
            long long neighbourPriceEdge = neighbour.second;
            if (distanceArray[neighbourVertex].first > topPriceEdge + neighbourPriceEdge) {
                distanceArray[neighbourVertex].first = topPriceEdge + neighbourPriceEdge;
                distanceArray[neighbourVertex].second = distanceArray[topVertex].second;
                priorityQueueMade.push({distanceArray[neighbourVertex].first, neighbourVertex});
            }
            else if (distanceArray[neighbourVertex].first == topPriceEdge + neighbourPriceEdge) {
                distanceArray[neighbourVertex].second += distanceArray[topVertex].second;
                distanceArray[neighbourVertex].second %= MODULE;
            }
        }
    }

}

int main()
{
    long long numberOfVertices;
    long long numberOfEdges;
 
    cin >> numberOfVertices >> numberOfEdges;

    long long startEdge;
    long long finishEdge;
    long long priceEdge;

    for (long long i = 1; i <= numberOfEdges; i++) {
        cin >> startEdge >> finishEdge >> priceEdge;
        graphMade[startEdge].push_back({finishEdge, priceEdge});
    }

    dijkstraMade(1);

    if (distanceArray[numberOfVertices].first == LONG_MAX) {
        cout << "-1 0";
    }
    else {
        cout << distanceArray[numberOfVertices].first << " " << distanceArray[numberOfVertices].second % MODULE;
    }

    return 0;
}
