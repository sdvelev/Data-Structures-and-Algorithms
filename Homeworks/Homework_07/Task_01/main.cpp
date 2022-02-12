#include <cmath>
#include <cstdio>
#include <vector>
#include<set>
#include<iterator>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    unsigned long long n;
    cin >> n;

    unsigned long long numberInDecimal;

    set<unsigned long long> collection;
    collection.insert(0);

    for (unsigned long long i = 0; i < n; i++) {
        cin >> numberInDecimal;
        unsigned long long current = numberInDecimal;

        while (current > 0) {
            collection.insert(current);
            unsigned long long nextSmaller = current - 1;
            current = nextSmaller & numberInDecimal;
        }
    }

    cout << collection.size();
    return 0;
}
