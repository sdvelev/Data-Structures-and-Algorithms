#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long maxKilledDemons(vector<pair<unsigned long long, unsigned long long>>& demonsPower) {

    vector<pair<unsigned long long, unsigned long long>> countArray(demonsPower.size());

    unsigned long long killedDemons = 0;

    for (int i = 0; i < demonsPower.size(); i++) {
        unsigned long long left = 0;
        unsigned long long right = killedDemons;

        while (left != right) {
            unsigned long long middle = left + (right - left) / 2;
            if (countArray[middle].first < demonsPower[i].first &&
              countArray[middle].second < demonsPower[i].second) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        countArray[left] = demonsPower[i];
        if (killedDemons == left) {
            ++killedDemons;
        }
    }

    return killedDemons;
}

int main()
{
    unsigned long long n;
    cin >> n;

    vector<pair<unsigned long long, unsigned long long>> demonsPower;
    unsigned long long attackPoints;
    unsigned long long defencePoints;

    for (size_t i = 0; i < n; i++) {
        cin >> attackPoints;
        cin >> defencePoints;

        demonsPower.push_back(make_pair(attackPoints, defencePoints));
    }
    
    sort(demonsPower.begin(), demonsPower.end());

    cout << maxKilledDemons(demonsPower);

    return 0;
}
