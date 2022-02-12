#include <cmath>
#include <cstdio>
#include <vector>
#include<set>
#include<map>
#include<iterator>
#include <iostream>
#include <algorithm>
using namespace std;


map<long long, long long> collection;
long long k, n;

long long calculate(long long & index, long long & number) {
    
    long long maxIndex = -10000;
    
    auto numberIter = collection.find(number); 
    
    
    if (numberIter == collection.begin()) {
        return -1;
    }
    
    --numberIter;
    
    while(numberIter != collection.begin()){
        if(numberIter->first + k >= number && numberIter->second < index && numberIter->first < number){
            if(maxIndex < numberIter->second){
                maxIndex = numberIter->second;
            }
            
        }
        else {
            break;
        }
        --numberIter;
    }
    
    if(numberIter->first + k >= number && numberIter->second < index && numberIter->first < number){
        if(maxIndex < numberIter->second){
                maxIndex = numberIter->second;
            }
    }
    
    if(maxIndex != -10000){
        return maxIndex;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    cin >> k;

    long long number;

    for (long long i = 0; i < n; i++) {
        cin >> number;

        if (collection.count(number) != 0) {
            collection[number] = i;
        }
        else {
            collection.insert({ number, i });
        }
        
        
        printf("%lld ", (calculate(i, number)));   
    }

    return 0;
}
