#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string word;
    cin >> word;

    sort(word.begin(), word.end());

    string numberResult;
    string lowerCaseResult;
    string upperCaseResult;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= '0' && word[i] <= '9') {
            numberResult.push_back(word[i]);
        }

        if (word[i] >= 'a' && word[i] <= 'z') {
            lowerCaseResult.push_back(word[i]);
        }

        if (word[i] >= 'A' && word[i] <= 'Z') {
            upperCaseResult.push_back(word[i]);
        }
    }

    cout << numberResult << lowerCaseResult << upperCaseResult;

    return 0;
}
