#include <cmath>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int numberOfRows;
int numberOfColumns;

long long uniquePairs = 0;

unordered_map<string, int> collection;

int main()
{
    cin >> numberOfRows >> numberOfColumns;

    int num;

    for (int i = 0; i < numberOfRows; i++) {
        string given = "";
        for (int j = 0; j < numberOfColumns; j++) {
            cin >> num;
            given += (to_string(num));
        }
        collection[given]++;
    }

    for (auto el : collection) {
        if (el.second == 1) {
            ++uniquePairs;
        }
    }

    cout << uniquePairs;

    return 0;
}
