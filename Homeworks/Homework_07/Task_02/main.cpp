#include <cmath>
#include <cstdio>
#include <vector>
#include<set>
#include<iterator>
#include <iostream>
#include <algorithm>
using namespace std;

set<int> collection;
vector<int> answer;

int calculate(int number, int index) {

    collection.insert(number);
    
    set<int>::iterator it;
    
    it = collection.find(number);
    
    int leftElement = -1;
    int rightElement = -1;
    
    int maxElement = *collection.rbegin();
    
    int result;
    
    if(it != collection.begin()){
        leftElement = *(--it);
        ++it;
    }
    
    if(*(it) != maxElement){
        rightElement = *(++it);
    }
    
    if(leftElement == -1){
        result = number ^ rightElement;   
    }
    else if(rightElement == -1){
        result = number ^ leftElement;   
    }
    else {
        int temp1 = number ^leftElement;
        int temp2 = number ^rightElement;
        result = min(temp1, temp2);
    }
    
    return min(result, answer[index - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int number;

    collection.insert(0);

    for (int i = 0; i < n; i++) {
        cin >> number;
        
        if(i == 0){
            answer.push_back(number);
            collection.insert(number);
            continue;
        }
        
        if(collection.count(number) != 0){
            answer.push_back(answer[i-1]);
            continue;
        }
        
        answer.push_back(calculate(number, i));
    }

    int size = answer.size();
    for (int i = 0; i < size; i++) {
        printf("%d \n", answer[i]);
    }

    return 0;
}
