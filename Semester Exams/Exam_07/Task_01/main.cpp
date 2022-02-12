#include <cmath>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<queue>
#include <algorithm>
using namespace std;

queue<int> collection;
queue<int> waitingQueue;
unordered_map<int, int> m;
vector<int> vec;

int main() {
    int numberOfQueries;
    cin >> numberOfQueries;
    
    int num;
    
    for(int i = 0; i < numberOfQueries; i++){
        cin >> num;
        vec.push_back(num);
        m[num]++;
    }
    
    for(int i = 0; i < numberOfQueries; i++){
        if(m[vec[i]] > 1){
            waitingQueue.push(vec[i]);
        }
        else if (m[vec[i]] > 0) {
            collection.push(vec[i]);
        }
        m.erase(vec[i]);
    }
    
    
    
    while(!collection.empty()){
        cout << collection.front() << " ";
        collection.pop();
    }
    
    while(!waitingQueue.empty()){
        cout << waitingQueue.front() << " ";
        waitingQueue.pop();
    }
    return 0;
}
