#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string originalWord;
    cin >> originalWord;

    int originalLength = originalWord.length();

    unsigned int letters;

    cin >> letters;

    char requiredLetter;
    unsigned int counter = 0;
    cin >> requiredLetter;

    for (int i = 0; i < originalLength; i++) {
        if (originalWord[i] == requiredLetter) {
            ++counter;
        }
    }

    counter = counter * (letters / originalLength);

    for (int i = 0; i < letters % originalLength; i++) {
        if (originalWord[i] == requiredLetter) {
            ++counter;
        }
    }

    cout << counter; 
    return 0;
}
