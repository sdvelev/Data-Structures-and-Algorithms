#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

class Ball {
public:
    int number;
    int colour;

    Ball() {
        this->number = 0;
        this->colour = 0;
    }

    Ball(int number, int colour) {
        this->number = number;
        this->colour = colour;
    }

};


struct Query{
    int first;
    int second;
    
    Query(){
        this->first = 0;
        this->second = 0;
    }
    
    Query(int first, int second){
        this->first = first;
        this->second = second;
    }
};

vector<Ball> collection;
vector<Query> queries;
int firstNumber = 0;

int serveQuery(Query& query) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (collection.empty()) {
        return -2;
    }

    Ball toAttack(firstNumber++, query.second);

    int positionToAdd;
    
    int size = collection.size();

    if (query.first < size / 2) {
        for (int i = 0; i < size; ++i) {
            if (query.first == collection[i].number) {
                positionToAdd = i + 1;
                collection.insert(collection.begin() + positionToAdd, toAttack);
                break;
            }
        }
    }
    else {
        for (int i = size - 1; i >= 0; --i) {
            if (query.first == collection[i].number) {
                positionToAdd = i + 1;
                collection.insert(collection.begin() + positionToAdd, toAttack);
                break;
            }
        }
    }

    int tempCounter = 0;
    int temp = positionToAdd;

    int startErase = 0;
    int endErase = collection.size();

    
    size = collection.size();
    while (temp >= 0 && temp < size - 1) {
        if (collection[temp].colour == collection[temp + 1].colour) {
            ++tempCounter;
            ++temp;

        }
        else {
            break;
        }
    }

    endErase = temp + 1;

    temp = positionToAdd;

    while (temp > 0 && temp < size) {
        if (collection[temp].colour == collection[temp - 1].colour) {
            ++tempCounter;
            --temp;
        }
        else {
            break;
        }
    }

    startErase = temp;

    ++tempCounter;

    if (tempCounter < 3) {
        return 0;
    }

    collection.erase(collection.begin() + startErase, collection.begin() + endErase);

    positionToAdd = startErase;

    while (positionToAdd > 0 && positionToAdd < collection.size() &&
        collection[positionToAdd].colour == collection[positionToAdd - 1].colour) {

        int tempCounter2 = 0;
        int temp2 = positionToAdd;

        int startErase2 = 0;
        int endErase2 = collection.size();

        size = collection.size();
        while (temp2 >= 0 && temp2 < size - 1) {
            if (collection[temp2].colour == collection[temp2 + 1].colour) {
                ++tempCounter2;
                ++temp2;
            }
            else {
                break;
            }
        }
        endErase2 = temp2 + 1;
        temp2 = positionToAdd;

        while (temp2 > 0 && temp2 < size) {
            if (collection[temp2].colour == collection[temp2 - 1].colour) {
                ++tempCounter2;
                --temp2;
            }
            else {
                break;
            }
        }
        startErase2 = temp2;
        ++tempCounter2;

        if (tempCounter2 < 3) {
            break;
        }
        else {
            collection.erase(collection.begin() + startErase2, collection.begin() + endErase2);
            positionToAdd = startErase2;

            tempCounter += tempCounter2;
        }

    }

    return tempCounter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfBalls;
    scanf("%d", &numberOfBalls);
    
    int ballColour;
    Ball toAdd;

    for (int i = 0; i < numberOfBalls; i++) {
        scanf("%d", &ballColour);
        toAdd.colour = ballColour;
        toAdd.number = firstNumber++;
        collection.push_back(toAdd);
    }

    int numberOfQueries;
    scanf("%d", &numberOfQueries);

    int numberOfBallToAttack;
    int colourOfMyBall;
    Query query;

    for (int i = 0; i < numberOfQueries; i++) {
        scanf("%d", &numberOfBallToAttack);
        scanf("%d", &colourOfMyBall);

        query.first = numberOfBallToAttack;
        query.second = colourOfMyBall;
        queries.push_back(query);
    }

    for (int i = 0; i < queries.size(); i++) {
        query = queries[i];
        int answer = serveQuery(query);
        if (answer == -2) {
            printf("Game Over \n");
        }
        else {
            printf("%d \n", answer);
        }
    }

    if (collection.empty()) {
        printf("-1 \n");
    }
    else {
        for (int i = 0; i < collection.size(); i++) {
            printf("%d ", collection[i].colour);
        }
    }

    return 0;
}
