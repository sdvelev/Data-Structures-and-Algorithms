#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr[1000001];
int counter = -1;

void calculate(int parentToStart) {
    ++counter;

    for(auto neighbour : arr[parentToStart]){
        calculate(neighbour);
    }
}

int main() {

    int numberOfNodes;
    cin >> numberOfNodes;

    int parent;
    int child;

    for (int i = 0; i < numberOfNodes - 1; i++) {
        cin >> parent;
        cin >> child;

        arr[parent].push_back(child);
    }

    for (int i = 0; i < numberOfNodes; i++) {
        calculate(i);
        cout << counter << " ";
        counter = -1;
    }
    
    return 0;
}
