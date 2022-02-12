#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, int>> collection;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tasksQueue;

int main()
{
    int numberOfTasks;
    cin >> numberOfTasks;
    int startTime;
    int duration;

    for (int i = 0; i < numberOfTasks; i++) {
        cin >> startTime >> duration;
        collection.push_back({ {startTime, duration}, i});
    }

    sort(collection.begin(), collection.end());

    int counter = 0;
    int size = collection.size();
    int printCounter = 0;

    for (long long startTimeIndex = 1; printCounter < numberOfTasks;) {
        while (collection[counter].first.first <= startTimeIndex && counter < size) {
            tasksQueue.push({ collection[counter].first.second, collection[counter].second});
            ++counter;
        }

        if (!tasksQueue.empty()) {
            pair<int, int> topElement = tasksQueue.top();
            tasksQueue.pop();
            cout << topElement.second << " ";
            ++printCounter;
            startTimeIndex += topElement.first;
        }
        else {
            startTimeIndex = collection[counter].first.first;
        }
    }
    
    return 0;
}
