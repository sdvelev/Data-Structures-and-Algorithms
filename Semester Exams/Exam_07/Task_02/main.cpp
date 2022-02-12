#include <cmath>
#include <cstdio>
#include <vector>
#include<unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> graph[2001][2001];
unordered_set<long long> unluckyNumbers;
vector<long long> answer;

bool isThereAWay(vector<int>& wayVector) {

    long long numberOfTowns = wayVector.size();

    for (int i = 0; i < numberOfTowns - 1; i++) {

        vector<long long> current = graph[wayVector[i]][wayVector[i + 1]];
        long long size = current.size();

        if (size == 0) {
            return 0;
        }

        long long counterLucky = 0;;
        long long counterUnlucky = 0;

        for (int j = 0; j < size; j++) {
            if (!unluckyNumbers.count(current[j])) {
                ++counterLucky;
            }
            else {
                ++counterUnlucky;
            }
        }

        if (counterUnlucky > 0 && counterLucky == 0) {
            return 0;
        }

    }
    return 1;
}

int main()
{
    long long numberOfVertices;
    cin >> numberOfVertices;

    long long numberOfEdges;
    cin >> numberOfEdges;

    long long startEdge;
    long long finishEdge;
    long long priceEdge;

    for (int i = 0; i < numberOfEdges; i++) {
        cin >> startEdge >> finishEdge >> priceEdge;
        graph[startEdge][finishEdge].push_back(priceEdge);
    }


    long long numberOfUnluckyNumbers;
    cin >> numberOfUnluckyNumbers;

    long long unluckyNumber;

    for (int i = 0; i < numberOfUnluckyNumbers; i++) {
        cin >> unluckyNumber;
        unluckyNumbers.insert(unluckyNumber);
    }

    long long numberOfWays;
    cin >> numberOfWays;

    long long lengthOfWay;
    long long town;

    for (int i = 0; i < numberOfWays; i++) {
        cin >> lengthOfWay;

        vector<int> wayVector(lengthOfWay);

        for (int j = 0; j < lengthOfWay; j++) {
            cin >> town;
            wayVector[j] = town;
        }


        answer.push_back(isThereAWay(wayVector));
    }

    long long size = answer.size();
    for (int i = 0; i < size; i++) {
        cout << answer[i];
    }
    return 0;
}
