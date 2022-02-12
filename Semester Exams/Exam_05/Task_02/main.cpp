#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

unordered_map<int, int> collection;

int main() {
    int numberOfElements;
    
    cin >> numberOfElements;
    int num;
    for(int i = 0; i < numberOfElements; i++){
        cin >> num;
        collection[num]++;
    }
    
    int sum = 0;
    
    for(auto el: collection){
        if(el.second % 2 != 0){
            sum += el.first*el.second;   
        }
    }
    cout << sum;
    return 0;
}
