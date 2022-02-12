#include <bits/stdc++.h>
using namespace std;


vector<pair<long long, long long>> collection;
priority_queue<long long, vector<long long>, greater<long long>> waitingQueue;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long numberOfStudents;
    cin >> numberOfStudents;

    long long handingTime;
    long long linesOfCode;

    for (long long i = 0; i < numberOfStudents; i++) {
        cin >> handingTime >> linesOfCode;
        collection.push_back({ handingTime, linesOfCode });
    }

    sort(collection.begin(), collection.end());

    long long currentTime = 0;
    long long totalHaltTime = 0;

    long long index = 0;

    while (index < numberOfStudents || waitingQueue.size() != 0) {
        while (index < numberOfStudents) {
            if (collection[index].first <= currentTime) {
                totalHaltTime = totalHaltTime - collection[index].first;
                waitingQueue.push(collection[index].second);
                ++index;    
            }
            else {
                break;
            }
        }

        if (waitingQueue.size() == 0) {
            if (index < numberOfStudents) {
                currentTime = collection[index].first;
                totalHaltTime = totalHaltTime - currentTime;
                waitingQueue.push(collection[index].second);
                ++index;
            }
        }

        long long toChoose = waitingQueue.top();
        waitingQueue.pop();
        currentTime = currentTime + toChoose;
        totalHaltTime = totalHaltTime + currentTime;
    }

    long double averageHaltTime = totalHaltTime / numberOfStudents;
    printf("%lld", (long long) averageHaltTime);
    return 0;
}
