#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct NodeMade {
    int data = 0;
    int counter = 0;
    NodeMade* left = nullptr;
    NodeMade* right = nullptr;

    NodeMade(int data) {
        this->data = data;
    }

    ~NodeMade() {
        delete left;
        delete right;
    }
};

class BinarySearchTreeMade {
private:
    NodeMade* root;
    NodeMade* insertMade(NodeMade* root, int value);
    void printMade(NodeMade* root);
    void fillCounter(NodeMade* root);
    NodeMade* deleteSpecificNodeMade(NodeMade* root, int toDelete);
public:
    BinarySearchTreeMade() {
        this->root = nullptr;
    }

    NodeMade* getRoot() const {
        return this->root;
    }

    void insertMade(int value) {
        this->root = this->insertMade(this->root, value);
    }

    void fillCounter() {
        fillCounter(this->root);
    }

    void deleteSpecificNodeMade(int toDelete) {
        this->deleteSpecificNodeMade(this->root, toDelete);
    }
       
    void printMade() {
        this->printMade(this->root);
    }
};

int counter = -1;

int countNodes(NodeMade* root) {
    if (!root) {
        return 0;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void BinarySearchTreeMade::fillCounter(NodeMade* root) {
    if (root) {
        fillCounter(root->left);
        root->counter = countNodes(root->left);
        fillCounter(root->right);
    }

}

NodeMade* BinarySearchTreeMade::insertMade(NodeMade* root, int value) {
    if (!root) {
        return new NodeMade(value);
    }

    if (value < root->data) {
        root->left = insertMade(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertMade(root->right, value);
    }
    
    return root;
}

NodeMade* minValue(NodeMade* current) {
    
    NodeMade* temp = current;

    while (temp->left) {
        temp = temp->left;
    }

    return temp;
}


NodeMade* BinarySearchTreeMade::deleteSpecificNodeMade(NodeMade* root, int toDelete) {

    if (!root) {
        return nullptr;
    }

    if (toDelete < root->data) {
        root->left = deleteSpecificNodeMade(root->left, toDelete);
    }
    else if (toDelete > root->data) {
        root->right = deleteSpecificNodeMade(root->right, toDelete);
    }
    else {
        if (!root->left) {
            NodeMade* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            NodeMade* temp = root->left;
            delete root;
            return temp;
        }

        NodeMade* temp = minValue(root->right);

        root->data = temp->data;
        root->right = deleteSpecificNodeMade(root->right, temp->data);
    }
    return root;
}

void BinarySearchTreeMade::printMade(NodeMade* root) {
    if (!root) {
        return;
    }

    queue<NodeMade*> printQueue;

    printQueue.push(root);

    while (!printQueue.empty()) {
        NodeMade* firstElement = printQueue.front();
        printQueue.pop();

        cout << firstElement->data << " ";

        if (firstElement->left) {
            printQueue.push(firstElement->left);
        }
        if (firstElement->right) {
            printQueue.push(firstElement->right);
        }
    }

}

NodeMade* findKElement(NodeMade* root, int kThElement) {
    if (!root) {
        return nullptr;
    }

    if (root->counter + 1 == kThElement) {
        return root;
    }

    if (root->counter + 1 > kThElement) {
        return findKElement(root->left, kThElement);
    }
    return findKElement(root->right, kThElement - root->counter - 1);
   
}

int main()
{
    int numberOfNodes;
    cin >> numberOfNodes;

    int kThElement;
    cin >> kThElement;

    BinarySearchTreeMade bst;

    int newElement;

    for (int i = 0; i < numberOfNodes; i++) {
        cin >> newElement;
        bst.insertMade(newElement);
    }

    bst.fillCounter();

    NodeMade* toDelete = findKElement(bst.getRoot() , numberOfNodes - kThElement + 1);

    bst.deleteSpecificNodeMade(toDelete->data);

    bst.printMade();

    return 0;
}
