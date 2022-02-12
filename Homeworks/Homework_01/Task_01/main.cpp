#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string word;
    cin >> word;

    unsigned int wordLength = word.length();
    
    vector<int> result;

    result.assign(wordLength,1000000);

    char letter;
    cin >> letter;

    for (int i = 0; i < wordLength; i++) {
        if (word[i] == letter) {
            result[i] = 0;
            int oldIndex = i;
            for (int j = 1; i > 0; --i) {
                if (result[i - 1] > j && result[i - 1] != 0) {
                    result[i - 1] = j;
                    ++j;
                }
                if (result[i - 1] == 0)
                {
                    break;
                }
            }
            i = oldIndex;
            for (int k = 1; i < wordLength; ++i) {
                if ((i + 1) != wordLength) {
                    if (result[i + 1] > k && result[i+1] != 0) {
                        result[i + 1] = k;
                        ++k;
                    }
                    if (result[i + 1] == 0)
                    {
                        break;
                    }
               }
            }
            i = oldIndex;
        }
    }

    for (int i = 0; i < wordLength; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
