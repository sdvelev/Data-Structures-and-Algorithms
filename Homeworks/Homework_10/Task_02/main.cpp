#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> neighbourSeats = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
    long long rows;
    cin >> rows;

    long long cols;
    cin >> cols;

    long long durationOfFilm;
    cin >> durationOfFilm;

    long long numberOfIllStudents;
    cin >> numberOfIllStudents;

    long long rowIll;
    long long colIll;

    vector<bool>* checked = new vector<bool>[rows];

    for (long long i = 0; i < rows; i++) {
        checked[i].assign(cols, false);
    }

    queue<pair<long long, long long>> illQueue;
    queue<pair<long long, long long>> illQueue2;

    for (long long i = 0; i < numberOfIllStudents; i++) {
        cin >> rowIll;
        cin >> colIll;

        illQueue.push({ rowIll - 1, colIll - 1 });
        checked[rowIll - 1][colIll - 1] = true;
    }

    long long healthyStudents = rows * cols - numberOfIllStudents;
    
    long long  currentIter = 0;

    while (!illQueue.empty() && currentIter < durationOfFilm) {
        pair<long long, long long> currentElement = illQueue.front();
        illQueue.pop();

        for (long long t = 0; t < 4; t++) {
            long long nextIllRow = currentElement.first + neighbourSeats[t].first;
            long long nextIllCol = currentElement.second + neighbourSeats[t].second;

            if (nextIllRow < 0 || nextIllCol < 0 ||
                nextIllRow >= rows || nextIllCol >= cols || checked[nextIllRow][nextIllCol] == true) {
                continue;
            }

            illQueue2.push({ nextIllRow, nextIllCol });
            checked[nextIllRow][nextIllCol] = true; 
            --healthyStudents;
        }
        
        if (illQueue.empty()) {
            ++currentIter;
            queue<pair<long long, long long>> temp = illQueue;
            illQueue = illQueue2;
            illQueue2 = temp;
        }  
    }

    cout << healthyStudents;
    return 0;
}
