#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;  // Added prev pointer for doubly linked list
};

class LinkedList {
private:
    Node* pHead;
    Node* pTail;
    int curN;

public:
    LinkedList() {
        pHead = nullptr;
        pTail = nullptr;
        curN = 0;
    }

    LinkedList(int x) {
        curN = 1;
        pHead = pTail = createNode(x);
    }

    ~LinkedList() {
        while (pHead) {
            Node* temp = pHead;
            pHead = pHead->next;
            delete temp;
        }
    }

    static Node* createNode(const int& val) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = nullptr;
        temp->prev = nullptr;  // Initialize prev to nullptr
        return temp;
    }

    void addHead(const int& n) {
        Node* temp = createNode(n);
        if (!pHead) {
            pHead = pTail = temp;
        } else {
            temp->next = pHead;
            pHead->prev = temp;
            pHead = temp;
        }
        curN++;  // Increase the count
    }

    void addTail(const int& n) {
        Node* temp = createNode(n);
        if (!pHead) {
            pHead = pTail = temp;
        } else {
            pTail->next = temp;
            temp->prev = pTail;
            pTail = temp;
        }
        curN++;  // Increase the count
    }

    Node* removeHead() {
        if (!pHead) return nullptr;
        Node* temp = pHead;
        pHead = pHead->next;
        if (pHead) pHead->prev = nullptr;
        else pTail = nullptr;
        delete temp;
        curN--;  // Decrease the count
        return pHead;
    }

    Node* removeTail() {
        if (!pHead) return nullptr;
        Node* temp = pTail;
        if (pHead == pTail) {
            delete pHead;
            pHead = pTail = nullptr;
            curN = 0;
            return nullptr;
        }
        pTail = pTail->prev;
        pTail->next = nullptr;
        delete temp;
        curN--;
        return pTail;
    }

    Node* getHead() const {
        return pHead;
    }

    Node* getTail() const {
        return pTail;
    }

    int getN() const {
        return curN;
    }
};
