#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comparator(pair<pair<double, double>, int> & pairOne, pair<pair<double, double>, int>& pairTwo) {
    if (pairOne.first.first > pairTwo.first.first) {
        return true;
    }
    else if (pairOne.first.first < pairTwo.first.first) {
        return false;
    }
    else {
        if (pairOne.first.second > pairTwo.first.second) {
            return true;
        }
        else if (pairOne.first.second < pairTwo.first.second) {
            return false;
        }
        else {
            if (pairOne.second > pairTwo.second) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<pair<pair<double, double>, int>> collection;
    double diameter;
    double time;
    double efficiency;


    for (int i = 0; i < n; i++) {
        cin >> diameter;
        cin >> time;

        efficiency = (diameter * diameter) / time;
        collection.push_back(make_pair(make_pair(efficiency, diameter), (i + 1)));
    }

    sort(collection.begin(), collection.end(), comparator);

    for (int i = 0; i < n; i++) {
        cout << collection[i].second << " ";
    }

    return 0;
}
