#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class BigInteger{
private:
    Node* pHead;
    Node* pTail;
public:
    // Contrustors
    BigInteger();
    BigInteger(long long num);
    BigInteger(int x, int n);
};
