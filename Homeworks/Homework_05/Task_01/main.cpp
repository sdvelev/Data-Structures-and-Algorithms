#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string word;
    cin >> word;
    int length = word.length();

    queue<char> toCheck;

    int countArray[62];

    for (int i = 0; i < 62; i++) {
        countArray[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        char currChar = word[i];
        toCheck.push(currChar);
        if (currChar >= '0' && currChar <= '9') {
            ++countArray[currChar - '0'];
        }
        else if (currChar >= 'A' && currChar <= 'Z') {
            ++countArray[currChar - 'A' + 10];
        }
        else if (currChar >= 'a' && currChar <= 'z') {
            ++countArray[currChar - 'a' + 36];
        }
    }


    int index = 0;

    while (!toCheck.empty()) {
        char firstElement = toCheck.front();
        if (firstElement >= '0' && firstElement <= '9') {
            if (countArray[firstElement - '0'] == 1) {
                cout << index++ << " ";
                toCheck.pop();
                countArray[firstElement - '0'] = -2;
                continue;
            }
            else {
                toCheck.pop();
                ++index;
                continue;
            }
        }
        else if (firstElement >= 'A' && firstElement <= 'Z') {
            if (countArray[firstElement - 'A' + 10] == 1) {
                cout << index++ << " ";
                toCheck.pop();
                countArray[firstElement - 'A' + 10] = -2;
                continue;
            }
            else {
                toCheck.pop();
                ++index;
                continue;
            }
        }
        else if (firstElement >= 'a' && firstElement <= 'z') {
            if (countArray[firstElement - 'a' + 36] == 1) {
                cout << index++ << " ";
                toCheck.pop();
                countArray[firstElement - 'a' + 36] = -2;
                continue;
            }
            else {
                toCheck.pop();
                ++index;
                continue;
            }
        }
    }


    return 0;
}
