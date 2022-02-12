#include <cmath>
#include <cstdio>
#include <vector>
#include<unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> kilogramsCollection;
unordered_map<long long, long long> divideElements;
unordered_map<long long, long long> multiplyElements;

int main()
{
    long long numberOfElements;
    cin >> numberOfElements;

    long long k;
    cin >> k;

    long long kilograms;

    for (long long i = 0; i < numberOfElements; i++) {
        cin >> kilograms;
        kilogramsCollection.push_back(kilograms);
    }
    
    long long counter = 0;
    long long currentElement;
    
    for (long long i = 0; i < numberOfElements; i++) {
        currentElement = kilogramsCollection[i];
        if (!multiplyElements.count(currentElement)) {
            multiplyElements.insert({ currentElement, 1 });
        }
        else {
            multiplyElements[currentElement] += 1;
        }
    }

    long long counterDivideElements;
    long long counterMultiplyElements;
    
    for (long long i = 0; i < numberOfElements; i++) {
        currentElement = kilogramsCollection[i];

        if (currentElement % k == 0) {
            counterDivideElements = divideElements[currentElement / k];
        }
        else {
            counterDivideElements = 0;
        }

        if (!divideElements.count(currentElement)) {
            divideElements.insert({ currentElement, 1 });
        }
        else {
            divideElements[currentElement] += 1;
        }

        if (multiplyElements.count(currentElement)) {
            multiplyElements[currentElement] -= 1;
        }

        if (multiplyElements.count(currentElement * k)){
            counterMultiplyElements = multiplyElements[currentElement * k];
        }
        else {
            counterMultiplyElements = 0;
        }

        counter += counterDivideElements * counterMultiplyElements;
    }
    
    cout << counter;
    return 0;
}
