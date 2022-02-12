#include <bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

long long numberOfRequiredOrders;
long long numberOfCooks;

vector<long long> times;

long long answer = 0;


long long calculateFunc(long long currentTime) {
    long long toReturn = 0;

    for (long long i = 0; i < times.size(); i++) {
        toReturn += (currentTime / times[i]);
    }
    return toReturn;
}

int main()
{
    cin >> numberOfRequiredOrders;
    cin >> numberOfCooks;

    long long currentTime;

    for (long long i = 0; i < numberOfCooks; i++) {
        cin >> currentTime;
        times.push_back(currentTime);
    }

    sort(times.begin(), times.end());

    long long left = 0;
    long long right = 1000000000000000;

    while (left <= right) {


        long long middle = left + (right - left) / 2;

        long long res = calculateFunc(middle);

        if (res >= numberOfRequiredOrders) {
            answer = middle;
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    cout << answer;
    return 0;
}
