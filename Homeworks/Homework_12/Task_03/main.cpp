#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_NUMBER_OF_VERTICES = 1000;
const long long MAX_NUMBER_OF_EDGES = 10000;
const long long MAX_SPEED_LIMIT = 30000;

pair<long long, pair<long long, long long>> edgeListMade[MAX_NUMBER_OF_EDGES + 7];
long long parentArrayMade[MAX_NUMBER_OF_VERTICES + 7], depthArrayMade[MAX_NUMBER_OF_VERTICES + 7];

long long numberOfVertices;
long long numberOfEdges;

long long countOfComponents;

long long minDifferenceInSpeeds = MAX_SPEED_LIMIT;
long long minSpeed;

long long findIfConnected(long long vertex) {
    if (parentArrayMade[vertex] == -1) {
        return vertex;
    }
    return parentArrayMade[vertex] = findIfConnected(parentArrayMade[vertex]);
}

void uniteDifferentComponents(long long fromVertex, long long toVertex) {

    long long rootFromVertex = findIfConnected(fromVertex);
    long long rootToVertex = findIfConnected(toVertex);

    if (rootFromVertex != rootToVertex) {
        if (depthArrayMade[rootFromVertex] < depthArrayMade[rootToVertex]) {
            parentArrayMade[rootFromVertex] = rootToVertex;
        }
        else if (depthArrayMade[rootFromVertex] > depthArrayMade[rootToVertex]) {
            parentArrayMade[rootToVertex] = rootFromVertex;
        }
        else {
            parentArrayMade[rootToVertex] = rootFromVertex;
            depthArrayMade[rootFromVertex]++;
        }
        countOfComponents--;
    }
}

void kruskalMade() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sort(edgeListMade, edgeListMade + numberOfEdges);

    for (int i = 0; i < numberOfEdges; i++) {

        for (int k = 1; k <= numberOfVertices; k++) {
            depthArrayMade[k] = 0;
            parentArrayMade[k] = -1;
        }

        long long priceVertex = edgeListMade[i].first;

        countOfComponents = numberOfVertices;

        for (int j = i; j < numberOfEdges; j++) {

            long long currentFromVertex = edgeListMade[j].second.first;
            long long currentToVertex = edgeListMade[j].second.second;
            long long currentPrice = edgeListMade[j].first;

            uniteDifferentComponents(currentFromVertex, currentToVertex);

            if (countOfComponents == 1) {
                if (currentPrice - priceVertex < minDifferenceInSpeeds) {
                    minDifferenceInSpeeds = currentPrice - priceVertex;
                    minSpeed = priceVertex;
                }
                break;
            }
        }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> numberOfVertices;
    cin >> numberOfEdges;

    long long fromVertex;
    long long toVertex;
    long long priceVertex;

    for (int i = 0; i < numberOfEdges; i++) {
        cin >> fromVertex >> toVertex >> priceVertex;

        edgeListMade[i] = { priceVertex, {fromVertex, toVertex} };
        edgeListMade[i] = { priceVertex, {toVertex, fromVertex} };
    }

    kruskalMade();

    cout << minSpeed << " " << minSpeed + minDifferenceInSpeeds;
    return 0;
}
