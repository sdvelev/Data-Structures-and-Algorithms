#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<set>
#include <iostream>
#include<climits>
#include <algorithm>
using namespace std;

const int MAX_NUMBER_OF_CROSSINGS = 100007;
vector<pair<int, pair<int, int>>> graphMade[MAX_NUMBER_OF_CROSSINGS];
int distArray[MAX_NUMBER_OF_CROSSINGS];
set<int> answerSet;

int numberOfCrossings;
int numberOfTunnels;
int batteryTime;

int dijkstraResult(int vertex, int currentKilograms) {
    for (int i = 1; i <= numberOfCrossings; i++) {
        distArray[i] = INT_MAX;
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> priorityQueueMade;
    distArray[vertex] = 0;
    priorityQueueMade.push({ distArray[vertex], {vertex, 0} });

    while (priorityQueueMade.size()) {
        pair<int, pair<int, int>> topElement = priorityQueueMade.top();
        priorityQueueMade.pop();
        int distanceToTopElementTime = topElement.first;
        int topVertex = topElement.second.first;
        int topWeight = topElement.second.second;
        
        if (distanceToTopElementTime > distArray[topVertex]) {
            continue;
        }

        for (auto neighbour : graphMade[topVertex]) {
            int neighbourVertex = neighbour.first;
            int neighbourDistanceTime = neighbour.second.first;
            int neighbourKilograms = neighbour.second.second;

            if (neighbourKilograms > currentKilograms) {
                continue;
            }

            if (distArray[neighbourVertex] > distArray[topVertex] + neighbourDistanceTime) {
                distArray[neighbourVertex] = distArray[topVertex] + neighbourDistanceTime;
                priorityQueueMade.push({ distArray[neighbourVertex], {neighbourVertex, neighbourKilograms} });
            }
        }

        if (topVertex == numberOfCrossings) {
            break;
        }
    }

    return distArray[numberOfCrossings];
}

int main()
{
    cin >> numberOfCrossings;
    cin >> numberOfTunnels;
    cin >> batteryTime;

    int startCrossing;
    int endCrossing;
    int kilogramsToLose;
    int timeToPass;

    int minKilograms = INT_MAX;
    int maxKilograms = INT_MIN;

    for (int i = 0; i < numberOfTunnels; i++) {
        cin >> startCrossing >> endCrossing >> kilogramsToLose >> timeToPass;
        graphMade[startCrossing].push_back({ endCrossing, {timeToPass, kilogramsToLose} });

        if(maxKilograms < kilogramsToLose) {
            maxKilograms = kilogramsToLose;
        }

        if (minKilograms > kilogramsToLose) {
            minKilograms = kilogramsToLose;
        }

    }

    while (minKilograms <= maxKilograms) {
        int middle = minKilograms + (maxKilograms - minKilograms) / 2;
        int currentDistanceTime = dijkstraResult(1, middle);
        if (currentDistanceTime > batteryTime) {
            minKilograms = middle + 1;
        }
        else {
            maxKilograms = middle - 1;
            answerSet.insert(maxKilograms + 1);
        }
    }
    
    if (answerSet.size()) {
        cout << *answerSet.begin();
    }
    else {
        cout << -1;
    }
    return 0;
}
