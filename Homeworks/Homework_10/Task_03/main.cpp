#include <cmath>
#include <cstdio>
#include <vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE_LETTERS = 130;

vector<string> collectionWords;
unordered_map<long long, vector<long long>> graphMade;
bool visitedVertices[MAX_SIZE_LETTERS] = {0};
stack<long long> helperStack;
unordered_set<int> collectionLetters;

void sortTopologically(long long vertex)
{
    visitedVertices[vertex] = 1;
    
    for (auto neighbour : graphMade[vertex])
    {
        if (visitedVertices[neighbour] == false) {
            sortTopologically(neighbour);
        }
    }
    
    helperStack.push(vertex);
}

int main()
{
    long long numberOfWords;
    cin >> numberOfWords;

    string word;

    char firstLetter = '\0';

    for (long long i = 0; i < numberOfWords; i++) {
        cin >> word;
        
        for(int j = 0; j < word.length(); j++){
            collectionLetters.insert({word[j]});
        }

        if (i == 0) {
            firstLetter = word[0];
        }

        collectionWords.push_back(word);
    }

    long long minimalWordLength;

    for (long long i = 0; i < numberOfWords; i++) {
        
        if(i == numberOfWords - 1){
            break;
        }
        
        string firstWord = collectionWords[i];
        string secondWord = collectionWords[i + 1];

        long long firstWordLength = firstWord.length();
        long long secondWordLength = secondWord.length();

        if (firstWordLength < secondWordLength) {
            minimalWordLength = firstWordLength;
        }
        else {
            minimalWordLength = secondWordLength;
        }

        for (long long j = 0; j < minimalWordLength; j++) {
            long long currentFirstLetter = (long long) firstWord[j];
            long long currentSecondLetter = (long long) secondWord[j];
            if (firstWord[j] != secondWord[j]) {
                
                if(!graphMade.count(currentFirstLetter)){
                    vector<long long> emptyVector;
                    emptyVector.push_back(currentSecondLetter);
                    graphMade.insert({currentFirstLetter, emptyVector});
                }
                else {
                    graphMade[currentFirstLetter].push_back(currentSecondLetter);
                }
                break;
            }
        }
    }

    sortTopologically(firstLetter);
    
    for(int i = 0; i < MAX_SIZE_LETTERS; i++){
        if(collectionLetters.count(i) && visitedVertices[i] == false){
            sortTopologically(i);
        }
    }
    
    while (helperStack.size()) {
        char currentElement = (char) helperStack.top();
        cout << currentElement << " ";
        helperStack.pop();
    }
    return 0;
}
