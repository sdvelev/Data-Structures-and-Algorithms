#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


struct ModifyHash {
    const long long BASE = 313;
    size_t operator()(const pair<long long, long long>& p) const {
        return (p.first * BASE) ^ p.second;
    }
};

const long long MOD1 = (long long)(1e9) + 7;
const long long MOD2 = (long long)(1e9) + 9;
const long long BASE = 313;

long long basePow1;
long long basePow2;
long long hash1;
long long hash2;

vector<string> collectionString;
unordered_map<pair<long long, long long>, long long, ModifyHash> countFrequency;
unordered_set<pair<long long, long long>, ModifyHash> collectionHashes;

bool isValid(long long middle) {

    for (int i = 0; i < 2; i++) {
        hash1 = 0;
        hash2 = 0;
        basePow1 = 1;
        basePow2 = 1;
        long long currentStringSize = collectionString[i].length();

        for (long long j = 0; j < middle; j++) {
            hash1 = (hash1 * BASE + collectionString[i][j]) % MOD1;
            hash2 = (hash2 * BASE + collectionString[i][j]) % MOD2;
        }

        for (long long j = 0; j < middle - 1; j++) {
            basePow1 = (basePow1 * BASE) % MOD1;
            basePow2 = (basePow2 * BASE) % MOD2;
        }

        collectionHashes.insert({hash1, hash2});

        for (long long j = middle; j < currentStringSize; j++) {
            hash1 = hash1 - (collectionString[i][j - middle] * basePow1) % MOD1;
            hash2 = hash2 - (collectionString[i][j - middle] * basePow2) % MOD2;
            
            if (hash1 < 0) {
                hash1 += MOD1;
            }
            
            if (hash2 < 0) {
                hash2 += MOD2;
            }
            
            hash1 = ((hash1 * BASE) + collectionString[i][j]) % MOD1;
            hash2 = ((hash2 * BASE) + collectionString[i][j]) % MOD2;
            collectionHashes.insert({hash1, hash2});
        }

        while (!collectionHashes.empty()) {
            pair<long long, long long> currentElement = *(collectionHashes.begin());
            if(countFrequency.count(currentElement)){
                countFrequency[currentElement]++;
            }
            else {
                countFrequency.insert({currentElement, 1});
            }
            collectionHashes.erase(currentElement);
            if (countFrequency[currentElement] == 2) {
                collectionHashes.clear();
                countFrequency.clear();
                return true;
            }
        }
        collectionHashes.clear();
    }
    
    countFrequency.clear();
    return false;
}

int main()
{
    string firstString;
    cin >> firstString;
    string secondString;
    cin >> secondString;

    collectionString.push_back(firstString);
    collectionString.push_back(secondString);

    long long minLength;

    if (collectionString[0].length() < collectionString[1].length()) {
        minLength = collectionString[0].length();
    }
    else {
        minLength = collectionString[1].length();
    }

    long long left = 0;
    long long right;

    right = minLength;

    while (left <= right) {
        long long middle = left + (right - left) / 2;

        if (isValid(middle)) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    cout << right;
    return 0;
}
