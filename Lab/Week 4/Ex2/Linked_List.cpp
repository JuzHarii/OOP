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
    void addHead(const int& n){
        Node* temp = createNode(n);
        if(!pHead){
            pHead = pTail = temp;
        }else{
            temp->next = pHead;
            pHead = temp;
        }
    }
    void addTail(const int& n){
        Node* temp = createNode(n);
        if(!pHead){
            pHead = pTail = temp;
        }else{
            pTail->next = temp;
            pTail = temp;
        }
    }
    Node* removeHead() {
        if (!pHead) {
            return nullptr;
        } else {
            Node* temp = pHead;
            pHead = pHead->next;
            delete temp;
            return pHead;
        }
    }
    Node* removeTail(){
        Node* temp = pHead;
        if(!pHead){
            return nullptr;
        }else if(pHead == pTail){
            delete pHead;
            pHead = pTail = nullptr;
            return nullptr;
        }else{
            while(temp->next != pTail){
                temp = temp->next;
            }
            delete pTail;
            pTail = temp;
            pTail->next = nullptr;
            return pTail;
        }
    }
    Node* getHead(){
        return pHead;
    }
};