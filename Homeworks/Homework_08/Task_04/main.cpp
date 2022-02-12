#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<set>
#include<iterator>
#include <iostream>
#include <algorithm>
using namespace std;


vector<pair<long long, long long>> collection;
vector<long long> operatorsCallTaken;
set<long long> freeOperators;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> waitingQueue;

int main()
{
    long long n, k;
    cin >> n >> k;

    operatorsCallTaken.assign(k, 0);

    long long callTime;
    long long duration;

    for (long long i = 0; i < n; i++) {
        cin >> callTime >> duration;
        collection.push_back({callTime, duration});
    }

    for (long long i = 0; i < k; i++) {
        if(i < n){
            long long endTime = collection[i].first + collection[i].second;
            waitingQueue.push({endTime, i});
            operatorsCallTaken[i] += 1;   
        }
    }

    for (long long i = k; i < n; i++) {
        if ((!waitingQueue.empty() && waitingQueue.top().first <= collection[i].first) || !freeOperators.empty()) {
            
            if (!waitingQueue.empty()) {
                while (waitingQueue.top().first <= collection[i].first) {
                    pair<long long, long long> topElement = waitingQueue.top();
                    freeOperators.insert(topElement.second);
                    waitingQueue.pop();
                    if (waitingQueue.empty()) {
                        break;
                    }
                }
            }

            set<long long>::iterator iter = freeOperators.lower_bound(i % k);

            if (iter == freeOperators.end()) {
                iter = freeOperators.begin();
            }
            
            long long operatorIndex = *iter;
            operatorsCallTaken[operatorIndex] += 1;
            long long endTime = collection[i].first + collection[i].second;
            waitingQueue.push({endTime, operatorIndex});

            freeOperators.erase(iter);

        }
    }

    vector<long long>::iterator maxElementIter = max_element(operatorsCallTaken.begin(), operatorsCallTaken.begin() + k);

    long long maxElement = *maxElementIter;

    for (long long i = 0; i < k; i++) {
        if (operatorsCallTaken[i] == maxElement) {
            cout << i << " ";
        }
    }
    
    return 0;
}
