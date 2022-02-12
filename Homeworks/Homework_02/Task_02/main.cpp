#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(pair<pair<string, string>, int>& timestampOne, pair<pair<string, string>, int>& timestampTwo) {
    int yearOne = (timestampOne.first.second[6] - '0') * 1000 + (timestampOne.first.second[7] - '0') * 100 +
        (timestampOne.first.second[8] - '0') * 10 + (timestampOne.first.second[9] - '0');
    int yearTwo = (timestampTwo.first.second[6] - '0') * 1000 + (timestampTwo.first.second[7] - '0') * 100 +
        (timestampTwo.first.second[8] - '0') * 10 + (timestampTwo.first.second[9] - '0');

    if (yearOne > yearTwo) {
        return false;
    }
    if (yearOne == yearTwo) {
        int monthOne = (timestampOne.first.second[3] - '0') * 10 + (timestampOne.first.second[4] - '0');
        int monthTwo = (timestampTwo.first.second[3] - '0') * 10 + (timestampTwo.first.second[4] - '0');

        if (monthOne > monthTwo) {
            return false;
        }

        if (monthOne == monthTwo) {
            int dayOne = (timestampOne.first.second[0] - '0') * 10 + (timestampOne.first.second[1] - '0');
            int dayTwo = (timestampTwo.first.second[0] - '0') * 10 + (timestampTwo.first.second[1] - '0');

            if (dayOne > dayTwo) {
                return false;
            }

            if (dayOne == dayTwo) {
                int hoursOne = (timestampOne.first.first[0] - '0') * 10 + (timestampOne.first.first[1] - '0');
                int hoursTwo = (timestampTwo.first.first[0] - '0') * 10 + (timestampTwo.first.first[1] - '0');

                if (hoursOne > hoursTwo) {
                    return false;
                }

                if (hoursOne == hoursTwo) {
                    int minutesOne = (timestampOne.first.first[3] - '0') * 10 + (timestampOne.first.first[4] - '0');
                    int minutesTwo = (timestampTwo.first.first[3] - '0') * 10 + (timestampTwo.first.first[4] - '0');

                    if (minutesOne > minutesTwo) {
                        return false;
                    }

                    if (minutesOne == minutesTwo) {
                        int secondsOne = (timestampOne.first.first[6] - '0') * 10 + (timestampOne.first.first[7] - '0');
                        int secondsTwo = (timestampTwo.first.first[6] - '0') * 10 + (timestampTwo.first.first[7] - '0');

                        if (secondsOne > secondsTwo) {
                            return false;
                        }
                        else if (secondsOne == secondsTwo){
                            if(timestampOne.second > timestampTwo.second){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<pair<string, string>,int>> collection;
    pair<string, string> timestamp;
    string time;
    string date;

    for (int i = 0; i < n; i++) {
        cin >> time;
        cin >> date;

        timestamp.first = time;
        timestamp.second = date;

        collection.push_back(make_pair(timestamp, i + 1));
    }

    sort(collection.begin(), collection.end(), comparator);

    for (int i = 0; i < n; i++) {
        cout << collection[i].second << endl;
    }

    return 0;
}
