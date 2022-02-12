#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void mergeMade(vector<int>& vec, int left, int middle, int right) {

    vector<int> firstVector;
    vector<int> secondVector;


    for (int i = 0; i < middle - left + 1; i++) {
        firstVector.push_back(vec[left + i]);
    }

    for (int i = 0; i < right - middle; i++) {
        secondVector.push_back(vec[middle + i + 1]);
    }

    size_t indexOfFirstVector = 0;
    size_t indexOfSecondVector = 0;

    size_t indexOfMergedVector = left;

    while (indexOfFirstVector < middle - left + 1 && indexOfSecondVector < right - middle) {
        if (firstVector[indexOfFirstVector] <= secondVector[indexOfSecondVector]) {
            vec[indexOfMergedVector] = firstVector[indexOfFirstVector];
            ++indexOfFirstVector;
        }
        else {
            vec[indexOfMergedVector] = secondVector[indexOfSecondVector];
            ++indexOfSecondVector;
        }
        ++indexOfMergedVector;
    }

    while (indexOfFirstVector < middle - left + 1) {
        vec[indexOfMergedVector] = firstVector[indexOfFirstVector];
        ++indexOfFirstVector;
        ++indexOfMergedVector;
    }

    while (indexOfSecondVector < right - middle) {
        vec[indexOfMergedVector] = secondVector[indexOfSecondVector];
        ++indexOfSecondVector;
        ++indexOfMergedVector;
    }

}

void sortMade(vector<int>& vec, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;

        sortMade(vec, left, middle);
        sortMade(vec, middle + 1, right);

        mergeMade(vec, left, middle, right);
    }
}

int main()
{
    int n;
    cin >> n;

    int number;

    vector<int> collections;

    for (int i = 0; i < n; i++) {
        cin >> number;
        collections.push_back(number);
    }

    unsigned int numberOfStaff;
    cin >> numberOfStaff;
    
    sortMade(collections, 0, n - 1);

    long long minimumSum = 0;
    for (int i = 0; i < numberOfStaff; i++) {
        minimumSum += collections[i];
    }

    cout << minimumSum;

    return 0;
}
