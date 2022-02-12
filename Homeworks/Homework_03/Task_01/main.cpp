#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<bool, unsigned long long> binarySearch(long double begin, long double end, unsigned long long element) {
    if (begin > end) {
        return  make_pair(false, (unsigned long long) end);
    }
    long double middle = (unsigned long long) (begin + (end - begin) / 2);
    
    if((middle * middle * middle) < 0){
        return binarySearch(begin, middle - 1, element);
    }
    else {
        if ((middle) == ((element / middle)/middle)) {
            return make_pair(true, 0);
        }
        if ((middle) > ((element/middle)/middle)) {
            return binarySearch(begin, middle - 1, element);
        }
        if ((middle) <  ((element/middle)/middle)) {
            return binarySearch(middle + 1, end, element);
        }
    }
    return make_pair(false, 0);
}

unsigned long long NearestCubeRoot(unsigned long long number) {
    if(number == 1){
        return number;
    }
    
    pair<bool, unsigned long long> result = binarySearch(1, number / 2, number);

    if (result.first) {
        return number;
    }
    else {
        return result.second;
    }
}

int main() {
    unsigned long long n;
    cin >> n;

    int numberOfPresents = 0;
    long double nearestCubeRoot;

    for (size_t long long i = n; i > 0;) {
        nearestCubeRoot = NearestCubeRoot(i);

        i = i - (nearestCubeRoot * nearestCubeRoot * nearestCubeRoot);
        ++numberOfPresents;
    }

    cout << numberOfPresents;

    return 0;
}
