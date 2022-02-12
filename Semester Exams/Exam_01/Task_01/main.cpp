#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void mergeMade(vector<int>& vec, int left, int middle, int right) {
    vector<int> leftVector;
    vector<int> rightVector;

    for (int i = left; i <= middle; i++) {
        leftVector.push_back(vec[i]);
        }

    for (int i = middle + 1; i <= right; i++) {
        rightVector.push_back(vec[i]);
        }

    int i = 0;
    int j = 0;
    int index = left;

    while (i < leftVector.size() && j < rightVector.size()) {
    if (leftVector[i] < rightVector[j]) {
        vec[index++] = leftVector[i++];
    }
    else {
        vec[index++] = rightVector[j++];
    }
    }

    while (i < leftVector.size()) {
        vec[index++] = leftVector[i++];
    }   

    while (j < rightVector.size()) {
        vec[index++] = rightVector[j++];
    }
}

void sortMade(vector<int> & vec, int left, int right) {
    if (right <= left) {
       return;
    }

    int middle = left + (right - left) / 2;

    sortMade(vec, left, middle);
    sortMade(vec, middle + 1, right);

    mergeMade(vec, left, middle, right);
    }

int main()
    {
    int n;
    cin >> n;

    int number;
    vector<int> collection;
    
    for (int i = 0; i < n; i++) {
        cin >> number;
        collection.push_back(number);
    }
        

    sortMade(collection, 0, n - 1);

        
    cout << collection[0] << " ";
    for (int i = 1; i < collection.size(); i++) {
        if (collection[i] != collection[i - 1]) {
                cout << collection[i] << " ";
            }
    }
    return 0;
}
