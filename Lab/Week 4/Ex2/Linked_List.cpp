#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node *pHead, *pTail;
    int curN;
public:
    LinkedList(){
        pHead = nullptr;
        pTail = nullptr;
    }
    LinkedList(int x){
        curN = 1;
        pHead = pTail = createNode(x);
    }
    ~LinkedList(){
        while(pHead){
            Node* temp = pHead;
            pHead = pHead->next;
            delete temp;
        }
    }
    static Node* createNode(const int& val){
        Node* temp = new Node;
        temp->data = val;
        temp->next = nullptr;
        return temp;
    }
    void addHead(const int& n) {
        Node* temp = createNode(n);
        if (!pHead) {
            pHead = pTail = temp;
        } else {
            temp->next = pHead;
            pHead = temp;
        }
        curN++; // Increase the count
    }

    void addTail(const int& n) {
        Node* temp = createNode(n);
        if (!pHead) {
            pHead = pTail = temp;
        } else {
            pTail->next = temp;
            pTail = temp;
        }
        curN++; // Increase the count
    }

    Node* removeHead() {
        if (!pHead) return nullptr;
        Node* temp = pHead;
        pHead = pHead->next;
        delete temp;
        curN--; // Decrease the count
        if (!pHead) pTail = nullptr;
        return pHead;
    }

    Node* removeTail() {
        if (!pHead) return nullptr;
        Node* temp = pHead;
        if (pHead == pTail) {
            delete pHead;
            pHead = pTail = nullptr;
            curN = 0;
            return nullptr;
        }
        while (temp->next != pTail) {
            temp = temp->next;
        }
        delete pTail;
        pTail = temp;
        pTail->next = nullptr;
        curN--; // Decrease the count
        return pTail;
    }
    Node* getHead(){
        return pHead;
    }
    Node* getTail(){
        return pTail;
    }
};