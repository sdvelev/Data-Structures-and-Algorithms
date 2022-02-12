#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_PARTICIPANTS = 100000;
int answers[MAX_PARTICIPANTS];
int main() {
    int numberOfParticipants;
    cin >> numberOfParticipants;

    vector<int> collection;
    int participantHunger;

    for (int i = 0; i < numberOfParticipants; i++) {
        cin >> participantHunger;
        collection.push_back(participantHunger);
    }

    int currParticipant = collection[0];

    stack<int> indexesCollection;
    indexesCollection.push(0);
    
    for (int i = 1; i < numberOfParticipants; i++) {
        if (collection[i - 1] < collection[i]) {
            answers[i] = 1;
        }

        if (collection[i] < currParticipant) {
            currParticipant = collection[i];
        }

        while (indexesCollection.size() > 0) {
            int topElement = indexesCollection.top();
            if (collection[i] <= collection[topElement]) {
                if (currParticipant < collection[i] && answers[i] < answers[topElement] + 1) {
                    answers[i] = answers[topElement] + 1;
                }
            }
            else {
                break;
            }
            indexesCollection.pop();
        }

        indexesCollection.push(i);
    }

    int requiredDays = 0;
    for (int i = 1; i < 100000; i++) {
        if (requiredDays < answers[i]) {
            requiredDays = answers[i];
        }

        if (i >= numberOfParticipants) {
            break;
        }

    }

    cout << requiredDays;
    return 0;
}
