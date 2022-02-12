#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<bool, pair<int, int>> binarySearch(vector<unsigned int>& complexityCollection,  int begin,  int end, unsigned int& element) {
    if (begin > end) {
        return  make_pair(false, make_pair(end, begin));
    }
    int middle = (begin + end) / 2;
    if (complexityCollection[middle] == element) {
        return make_pair(true, make_pair(0, 0));
    }
    if (complexityCollection[middle] > element) {
        return binarySearch(complexityCollection, begin, middle - 1 , element);
    }
    if (complexityCollection[middle] < element) {
        return binarySearch(complexityCollection, middle + 1, end, element);
    }
    
    return make_pair(false, make_pair(0, 0));
}


unsigned int requiredComplexity(vector<unsigned int>& complexityCollection, unsigned int& element) {
    pair<bool, pair<int, int>> result = binarySearch(complexityCollection, 0, complexityCollection.size() - 1, element);

    if (result.first) {
        return element;
    }
    else {
        int leftElement = complexityCollection[result.second.first];
        if (result.second.second == complexityCollection.size()) {
            return leftElement;
        }
        int rightElement = complexityCollection[result.second.second];

        if ((element - leftElement) < (rightElement - element)) {
            return leftElement;
        }
        else if ((element - leftElement) > (rightElement - element)) {
            return rightElement;
        }
        else {
            return leftElement;
        }
    }
}


int main()
{
    unsigned int numberOfProjects;
    unsigned int numberOfTeams;

    cin >> numberOfProjects;
    cin >> numberOfTeams;

    unsigned int complexity;
    unsigned int knowledge;

    vector<unsigned int> complexityCollection;
    vector<unsigned int> knowledgeCollection;

    for (int i = 0; i < numberOfProjects; i++) {
        cin >> complexity;
        complexityCollection.push_back(complexity);
    }

    for (int i = 0; i < numberOfTeams; i++) {
        cin >> knowledge;
        knowledgeCollection.push_back(knowledge);
    }

    sort(complexityCollection.begin(), complexityCollection.end());

    unsigned int knowledgeTeam;
    for (int i = 0; i < numberOfTeams; i++) {
        knowledgeTeam = knowledgeCollection[i];

        if (knowledgeTeam < complexityCollection[0]) {
            cout << complexityCollection[0] << endl;
        }
        else {
            cout << requiredComplexity(complexityCollection, knowledgeTeam) << endl;
        }
    }

    return 0;
}
