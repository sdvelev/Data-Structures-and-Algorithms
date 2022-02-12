#include <cmath>
#include <cstdio>
#include <vector>
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<string, int> collection;
vector<string> answer;

int main() {
    int numberOfStrings;
    cin >>numberOfStrings;
    
    string rmd;
    
    for(int i = 0; i < numberOfStrings; i++){
        cin >> rmd;
        answer.push_back(rmd);
        collection[rmd]++;
    }
    
    for(int i = 0; i < numberOfStrings; i++){
        cout << collection[answer[i]] << " ";
    }
    return 0;
}
