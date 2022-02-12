#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct NodeMade {
    long long data;
    NodeMade* prev;
    NodeMade* next;

    NodeMade() {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }

    NodeMade(int data, NodeMade* prev, NodeMade* next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class DoublyLinkedListMade {
private:
    NodeMade* head;
    NodeMade* tail;
    NodeMade* middle;

    long long size;

public:

    DoublyLinkedListMade() {
        this->head = nullptr;
        this->middle = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void pop_back() {
        if (this->head == nullptr || this->tail == nullptr) {
            return;
        }

        --this->size;

        if (this->middle != nullptr) {
            if (this->size % 2 != 0) {
                this->middle = this->middle->prev;
            }
        }

        if(this->tail->prev != nullptr){
            this->tail = this->tail->prev;
            delete this->tail->next;   
            this->tail->next = nullptr;
        }
        else {
            this->tail->prev = nullptr;
            this->tail->next = nullptr;
            this->tail = nullptr;
            this->head = nullptr;
            this->middle = nullptr;
        }
        
    }

    void push_back(long long data) {
        ++this->size;

        if (this->tail == nullptr || this->head == nullptr) {
            this->head = new NodeMade(data, nullptr, nullptr);
            this->tail = this->head;
            this->middle = this->head;
            return;
        }

        this->tail->next = new NodeMade(data, this->tail, nullptr);
        this->tail = this->tail->next;

        if (this->size % 2 == 0) {
            if(this->middle != nullptr){
                this->middle = this->middle->next;   
            }
        }
    }

    void middleOperation() {
        
        if(this->size == 0 || this->size == 1){
            return;
        }
        
        auto oldHead = this->head;
        auto oldTail = this->tail;

        this->tail->next = this->head;

        this->tail = this->middle->prev;

        this->middle->prev->next = nullptr;

        this->head = this->middle;


        this->head->prev = nullptr;

        if (this->size % 2 == 0) {
            this->middle = oldHead;
            this->middle->prev = oldTail;
            this->middle->prev->next = this->middle;
        }
        else {
            this->middle = oldTail;
            this->middle->next = oldHead;
            this->middle->next->prev = this->middle;
        }
    }

    bool empty() {
        if (this->head == nullptr || this->tail == nullptr) {
            return true;
        }
        return false;
    }

    long long getSize() const{
        return this->size;
    }
    
    NodeMade* begin() {
        return this->head;
    }

    NodeMade* end() {
        return this->tail;
    }

};



DoublyLinkedListMade collection;

void addQuery(const long long& number) {
    collection.push_back(number);
}

void gunQuery() {
    if (!collection.empty()) {
        collection.pop_back();
    }
}

void milenQuery() {
    if (!collection.empty()) {
        collection.middleOperation();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long numberOfQueries;
    cin >> numberOfQueries;

    string query;
    long long number;

    for (long long i = 0; i < numberOfQueries; i++) {

        cin >> query;

        if (query == "gun") {
            gunQuery();
        }
        else if (query == "milen") {
            milenQuery();
        }
        else if (query == "add") {
            cin >> number;
            if (number <= numberOfQueries) {
                addQuery(number);
            }
        }

    }

    printf("%lu \n", collection.getSize());

    
    for (auto i = collection.begin(); i != nullptr;) {
        printf("%lld ", i->data);
        i = i->next;
    }

    return 0;
}
