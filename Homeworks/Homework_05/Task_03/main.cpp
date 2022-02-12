#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int numberOfElements;
    cin >> numberOfElements;

    vector<int> collection;
    int element;

    int lengthOfSubVectors;
    cin >> lengthOfSubVectors;

    for (int i = 0; i < numberOfElements; i++) {
        cin >> element;
        collection.push_back(element);
    }

    int size = collection.size();

    long long minimalSum = 0;

    deque<int> currentSubsequence;

    int index = 0;
    for (int i = 0; i < lengthOfSubVectors; i++) {

        while (currentSubsequence.size() != 0 && collection[i] <= collection[currentSubsequence.back()]) {
            currentSubsequence.pop_back();
        }

        currentSubsequence.push_back(i);
        ++index;
    }

    while (index < size) {
        minimalSum = minimalSum + collection[currentSubsequence.front()];

        if (currentSubsequence.size() != 0) {
            while (currentSubsequence.size() != 0 && currentSubsequence.front() <= index - lengthOfSubVectors) {
                currentSubsequence.pop_front();
                if (currentSubsequence.size() == 0) {
                    break;
                }
            }
        }
        
        if (currentSubsequence.size() != 0) {
            while (currentSubsequence.size() != 0 && collection[index] <= collection[currentSubsequence.back()]) {
                currentSubsequence.pop_back();
                if (currentSubsequence.size() == 0) {
                    break;
                }
            }
        }
        

        currentSubsequence.push_back(index);
        ++index;
    }

    minimalSum = minimalSum + collection[currentSubsequence.front()];

    cout << minimalSum;
    return 0;
}
