#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<climits>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_NUMBER_OF_VERTICES = 100009;
const long long UNUSED = 100007;

vector<pair<long long, long long>> graphMade[MAX_NUMBER_OF_VERTICES];
long long distanceArray[MAX_NUMBER_OF_VERTICES + 1];

vector<long long> answerVector;

void dijkstraMade(long long startVertex) {
    for (long long i = 0; i < MAX_NUMBER_OF_VERTICES; i++) {
        distanceArray[i] = LONG_MAX;
    }

    distanceArray[startVertex] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> priorityQueueMade;
    priorityQueueMade.push({ distanceArray[startVertex], startVertex });

    while (priorityQueueMade.size()) {
        pair<long long, long long> topPair = priorityQueueMade.top();
        priorityQueueMade.pop();
        long long topVertex = topPair.second;
        long long topPriceEdge = topPair.first;

        if (topPriceEdge > distanceArray[topVertex]) {
            continue;
        }

        for (auto neighbour : graphMade[topVertex]) {
            long long neighbourVertex = neighbour.first;
            long long neighbourPriceEdge = neighbour.second;
            if (distanceArray[neighbourVertex] > topPriceEdge + neighbourPriceEdge) {
                distanceArray[neighbourVertex] = topPriceEdge + neighbourPriceEdge;
                priorityQueueMade.push({ distanceArray[neighbourVertex], neighbourVertex });
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long numberOfVertices;
    long long numberOfEdges;

    cin >> numberOfVertices >> numberOfEdges;

    long long startEdge;
    long long finishEdge;
    long long priceEdge;

    for (long long i = 1; i <= numberOfEdges; i++) {
        cin >> startEdge >> finishEdge >> priceEdge;
        graphMade[startEdge].push_back({ finishEdge, priceEdge });
        graphMade[finishEdge].push_back({ startEdge, priceEdge });
    }

    long long numberOfFinsihSetElements;
    cin >> numberOfFinsihSetElements;

    long long finishVertex;

    long long addedVertex = UNUSED;

    for (int i = 0; i < numberOfFinsihSetElements; i++) {
        cin >> finishVertex;
        graphMade[addedVertex].push_back({finishVertex, 0});
        graphMade[finishVertex].push_back({addedVertex, 0});
    }

    dijkstraMade(addedVertex);

    long long numberOfQueries;
    cin >> numberOfQueries;
    
    long long startVertex;

    long long answer;

    for (int i = 0; i < numberOfQueries; i++) {
        cin >> startVertex;
        answer = distanceArray[startVertex];
        answerVector.push_back(answer);
    }

    long long size = answerVector.size();
    for (long long i = 0; i < size; i++) {
        printf("%lld\n", answerVector[i]);
    }

    return 0;
}
