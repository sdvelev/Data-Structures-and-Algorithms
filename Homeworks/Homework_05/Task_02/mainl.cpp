#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<deque>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> successfullyPassed;
    vector<int> warriorsCollection;

    deque<int> leftWarriors;
    queue<int> rightWarriors;

    int numberOfWarriors;
    cin >> numberOfWarriors;

    int warriorPower;

    for (int i = 0; i < numberOfWarriors; i++) {
        cin >> warriorPower;
        warriorsCollection.push_back(warriorPower);
    }

    int i = 0;

    while (i < numberOfWarriors) {
        for (i; i < numberOfWarriors && warriorsCollection[i] >= 0; i++) {
            leftWarriors.push_front(warriorsCollection[i]);
        }

        for (; i < numberOfWarriors && warriorsCollection[i] <= 0; i++) {
            rightWarriors.push(-warriorsCollection[i]);
        }

        while (!leftWarriors.empty() && !rightWarriors.empty()) {
            if (leftWarriors.front() > rightWarriors.front()) {
                rightWarriors.pop();
            }
            else if (leftWarriors.front() < rightWarriors.front()) {
                leftWarriors.pop_front();
            }
            else {
                leftWarriors.pop_front();
                rightWarriors.pop();
            }
        }

        if (i >= numberOfWarriors && !leftWarriors.empty()) {
            int size = leftWarriors.size();
            for (int j = 0; j < size; j++) {
                successfullyPassed.push_back(leftWarriors.back());
                leftWarriors.pop_back();  
            }
        }

        if (!rightWarriors.empty()) {
            int size = rightWarriors.size();
            for (int j = 0; j < size; j++) {
                successfullyPassed.push_back(-rightWarriors.front());
                rightWarriors.pop();
            }
        }
    }

    if (successfullyPassed.empty()) {
        printf("\n");
        return 0;
    }
    
    int successfullyPassedSize = successfullyPassed.size();
    
    for (int i = 0; i < successfullyPassedSize; i++) {
        printf("%d ", successfullyPassed[i]);
    }

    return 0;
}
