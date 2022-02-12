#include <cmath>
#include <cstdio>
#include <vector>
#include<unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
  
    vector<int> collectionDoors;
    vector<int> collectionKeys;
    unordered_map<int, int> possesedKeys;

int main()
{
 
    int numberOfElements;
    cin >> numberOfElements;
    
    int num;
    
    for(int i = 0; i < numberOfElements; i++){
        cin >> num;
        collectionKeys.push_back(num);
    }
    
    for(int i = 0; i < numberOfElements; i++){
        cin >> num;
        collectionDoors.push_back(num);
    }
    
    long long counter = 0;
    
    for(int i = 0; i < numberOfElements; i++){
        
        possesedKeys[collectionKeys[i]]++;
        
        if(possesedKeys.count(collectionDoors[i])){
            possesedKeys[collectionDoors[i]]--;
            
            if(possesedKeys[collectionDoors[i]] == 0){
                possesedKeys.erase(collectionDoors[i]);
            }
            
        }
        else {
            ++counter;
        }   
    }
    
    cout << counter;
    return 0;
}
