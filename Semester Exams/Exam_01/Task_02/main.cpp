#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool comparator(pair<pair<double, int>, int> & pairOne, pair<pair<double, int>, int> & pairTwo) {
    if (pairOne.first.first > pairTwo.first.first) {
        return true;
    }
    else if (pairOne.first.first < pairTwo.first.first) {
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

int main()
{
    int n;
    cin >> n;

    int participants;
    double participantsEnemy;
    double points;

    vector<pair<pair<double, int>, int>> results;
    pair<pair<double, int>, int> curResult;

    for (int i = 0; i < n; i++) {
        cin >> participants;
        cin >> participantsEnemy;
        curResult.first.first = (participants * participants) / participantsEnemy;
        curResult.first.second = i + 1;
        curResult.second = participants;

        results.push_back(curResult);
    }
    
    sort(results.begin(), results.end(), comparator);

    for (int i = 0; i < n; i++) {
        cout << results[i].first.second << " ";
    }

    return 0;
}
