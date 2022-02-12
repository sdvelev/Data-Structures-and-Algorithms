#include <iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

unsigned int binarySearchMade(vector<int>& collectionOfNumbers, int left, int right, const int & maxNumber){
    while(left <= right){
        int middle = left + (right - left) / 2;
        if(collectionOfNumbers[middle] == maxNumber){
            return middle;
        }
        else if(collectionOfNumbers[middle] > maxNumber){
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return left - 1;
}

int maxNumbers(vector<int>& collectionOfNumbers, long long & maxSum, const int & maxNumber) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int counter = 0;

    int start = binarySearchMade(collectionOfNumbers, 0, collectionOfNumbers.size() - 1, maxNumber);
    while(start < collectionOfNumbers.size() - 1 && collectionOfNumbers[start + 1] == collectionOfNumbers[start]){
        ++start;
    }

    if(start >= 0){
      while (maxSum >= 0) {
        maxSum -= collectionOfNumbers[start];
            if(maxSum < 0){
                break;
            }
            ++counter;
            --start;
            if(start < 0){
                break;
            }
    }  
    }
    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numberOfElements;
    int numberOfQueries;

    cin >> numberOfElements;
    cin >> numberOfQueries;
    
    vector<int> collectionOfNumbers;

    int number;
    for (size_t i = 0; i < numberOfElements; i++) {
        cin >> number;
        collectionOfNumbers.push_back(number);
    }
    
    sort(collectionOfNumbers.begin(), collectionOfNumbers.end());

    int maxNumber;
    long long maxSum;

    vector<int> answers;

    for (size_t i = 0; i < numberOfQueries; i++) {
        cin >> maxSum;
        cin >> maxNumber;

        printf("%d \n", maxNumbers(collectionOfNumbers, maxSum, maxNumber));
    }
    return 0;
}
