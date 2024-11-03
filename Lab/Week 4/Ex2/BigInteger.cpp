#include "BigInteger.h"

// ! display
ostream& operator<<(ostream& os, const BigInteger& bi){
    LinkedList list_temp = bi.list;
    Node* ptemp = list_temp.getHead();
    while(ptemp){
        os << ptemp->data;
        ptemp = ptemp->next;
    }
    return os;
}
// ! consttructors
BigInteger::BigInteger() : list(){}

BigInteger::BigInteger(long long n){
    while(n){
        list.addHead(n % 10);
        n /= 10;
    }
}

BigInteger::BigInteger(int x, int n){
    while(n--){
        list.addHead(x);
    }
}

BigInteger BigInteger::operator+(const BigInteger& bi){
    
}