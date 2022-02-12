#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct NodeMade {
    int data;
    int level;
    NodeMade* left;
    NodeMade* right;

    NodeMade(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    NodeMade(int data, int level) {
        this->data = data;
        this->level = level;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct ModifiedNode {
    NodeMade* node;
    int level;

    ModifiedNode(int level, NodeMade* node) {
        this->node = node;
        this->level = level;
    }
};

NodeMade* buildTree(vector<pair<int, int>> collection) {
    int numberOfNodes = collection.size();

    vector<NodeMade*> answer;

    for (int i = 0; i < numberOfNodes; i++) {
        answer.push_back(new NodeMade(i));
    }

    NodeMade* root = answer[0];

    for (int i = 0; i < numberOfNodes; i++) {
        int leftChild = collection[i].first;
        int rightChild = collection[i].second;

        if (leftChild != -1) {
            answer[i]->left = answer[leftChild];
        }
        else {
            answer[i]->left = nullptr;
        }

        if (rightChild != -1) {
            answer[i]->right = answer[rightChild];
        }
        else {
            answer[i]->right = nullptr;
        }
    }
    return root;
}

void calculate(NodeMade* root) {
    queue<ModifiedNode*> answerQueue;

    vector<pair<int, int>> answerVector;

    answerQueue.push(new ModifiedNode(0, root));

    while (!answerQueue.empty()) {
        ModifiedNode* firstElement = answerQueue.front();
        answerQueue.pop();

        if (answerVector.size() == 0) {
            answerVector.push_back({ firstElement->level, firstElement->node->data });
        }
        else {
            for (int i = 0; i < answerVector.size(); i++) {
                if (answerVector[i].first == firstElement->level) {
                    break;
                }
                else {
                    if (i == answerVector.size() - 1) {
                        answerVector.push_back({ firstElement->level, firstElement->node->data });
                        break;
                    }
                }
            }
        }

        if (firstElement->node->left) {
            answerQueue.push(new ModifiedNode(firstElement->level - 1, firstElement->node->left));
        }

        if (firstElement->node->right) {
            answerQueue.push(new ModifiedNode(firstElement->level + 1, firstElement->node->right));
        }
    }

    sort(answerVector.begin(), answerVector.end());

    for (int i = 0; i < answerVector.size(); i++){
        cout << answerVector[i].second << " ";
    }
}

int main()
{
    int numberOfNodes;
    cin >> numberOfNodes;

    vector<pair<int, int>> collection;
    int leftChild;
    int rightChild;

    for (int i = 0; i < numberOfNodes; i++) {
        cin >> leftChild;
        cin >> rightChild;

        collection.push_back({leftChild, rightChild});
    }

    NodeMade* root = buildTree(collection);

    calculate(root);

    return 0;
}
