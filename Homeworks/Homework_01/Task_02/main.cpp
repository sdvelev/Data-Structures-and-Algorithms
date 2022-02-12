#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    vector<int> container;
    int number;

    for (int i = 0; i < n; i++) {
        cin >> number;
        container.push_back(number);
    }

    sort(container.begin(), container.end());

    vector<int> newContainer;

    for (auto el : container) {
        if (el > 0)
            newContainer.push_back(el);
    }

    if (!newContainer.empty()) {
        if (newContainer[0] != 1) {
            cout << 1;
        }
        else {
            for (int i = 1; i < newContainer.size(); i++) {
                if (newContainer[i] != (newContainer[i - 1] + 1) && newContainer[i] != newContainer[i - 1]) {
                    cout << newContainer[i - 1] + 1;
                    break;
                }
                if (i == newContainer.size() - 1) {
                    cout << newContainer[i] + 1;
                    break;
                }
            }
        }
    }
    else {
        cout << 1;
    }

    return 0;
}
