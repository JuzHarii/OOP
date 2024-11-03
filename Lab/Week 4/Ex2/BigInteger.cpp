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
BigInteger::BigInteger() : list(0){}

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

BigInteger BigInteger::operator+(const BigInteger& bi) {
    LinkedList list_temp = bi.list;
    LinkedList list_res; // Result of the addition

    Node* ptemp1 = list.getHead(); // Pointer to traverse the current BigInteger's list
    Node* ptemp2 = list_temp.getHead(); // Pointer to traverse the other BigInteger's list

    int carry = 0;
    while (ptemp1 || ptemp2) {
        int sum = carry + (ptemp1 ? ptemp1->data : 0) + (ptemp2 ? ptemp2->data : 0);
        carry = sum / 10; // if sum >= 10, carry = 1, else carry = 0
        list_res.addHead(sum % 10); // Add each result digit to the head for reversed order
        
        if (ptemp1) ptemp1 = ptemp1->next;
        if (ptemp2) ptemp2 = ptemp2->next;
    }

    if (carry) {
        list_res.addHead(carry); // Add final carry at the head, if any
    }

    BigInteger res;
    res.list = list_res;
    return res;
}
