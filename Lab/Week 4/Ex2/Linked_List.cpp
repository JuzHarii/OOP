#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;  // doubly linked list
};

class LinkedList {
private:
    Node* pHead;
    Node* pTail;
    int curN;

public:
    LinkedList() : pHead(nullptr), pTail(nullptr), curN(0) {}

    LinkedList(int x) : curN(1) {
        pHead = pTail = createNode(x);
    }

    // Copy constructor
    LinkedList(const LinkedList& other) : pHead(nullptr), pTail(nullptr), curN(0) {
        Node* current = other.pHead;
        while (current) {
            addTail(current->data);
            current = current->next;
        }
    }

    // Assignment operator
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            // Clean up existing list
            while (pHead) {
                removeHead();
            }

            // Copy from other list
            Node* current = other.pHead;
            while (current) {
                addTail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Destructor
    ~LinkedList() {
        while (pHead) {
            removeHead();
        }
    }

    // Create a new node with error handling
    static Node* createNode(const int& val) {
        Node* temp = new (nothrow) Node;
        if (!temp) {
            cerr << "Memory allocation failed for node creation.\n";
            exit(1); // Exit if memory allocation fails
        }
        temp->data = val;
        temp->next = nullptr;
        temp->prev = nullptr;
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
        curN++;
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
        curN++;
    }

    void removeHead() {
        if (!pHead) return;
        Node* temp = pHead;
        pHead = pHead->next;
        if (pHead) pHead->prev = nullptr;
        else pTail = nullptr;
        delete temp;
        curN--;
    }

    void removeTail() {
        if (!pHead) return;
        Node* temp = pTail;
        if (pHead == pTail) {
            delete pHead;
            pHead = pTail = nullptr;
            curN = 0;
            return;
        }
        pTail = pTail->prev;
        pTail->next = nullptr;
        delete temp;
        curN--;
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
