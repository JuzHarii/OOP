#include "BigInteger.h"

// ! display
ostream& operator<<(ostream& os, const BigInteger& bi){
    Node* ptemp = bi.list.getHead();
    while(ptemp){
        os << ptemp->data;
        ptemp = ptemp->next;
    }
    return os;
}

// ! constructors
BigInteger::BigInteger() : list(0) {}

BigInteger::BigInteger(long long n){
    if (n == 0) {
        list.addHead(0);
    } else {
        while(n) {
            list.addHead(n % 10);
            n /= 10;
        }
    }
}

BigInteger::BigInteger(int x, int n){
    while(n--) {
        list.addHead(x);
    }
}

// ! addition operator
BigInteger BigInteger::operator+(const BigInteger& bi) {
    LinkedList list_temp = bi.list;
    LinkedList list_res;

    Node* ptemp1 = list.getTail();
    Node* ptemp2 = list_temp.getTail();

    int carry = 0;
    while (ptemp1 || ptemp2 || carry) {
        int sum = (ptemp1 ? ptemp1->data : 0) + (ptemp2 ? ptemp2->data : 0) + carry;

        list_res.addHead(sum % 10);
        carry = sum / 10;

        if (ptemp1) ptemp1 = ptemp1->prev;
        if (ptemp2) ptemp2 = ptemp2->prev;
    }

    BigInteger result;
    result.list = list_res;
    return result;
}

// ! subtraction operator
BigInteger BigInteger::operator-(const BigInteger& bi) {
    LinkedList list_temp = bi.list;
    LinkedList list_res;

    Node* ptemp1 = list.getTail();
    Node* ptemp2 = list_temp.getTail();

    int carry = 0;
    while (ptemp1 || ptemp2 || carry) {
        int digit1 = (ptemp1) ? ptemp1->data : 0;
        int digit2 = (ptemp2) ? ptemp2->data : 0;

        int sub = digit1 - digit2 - carry;

        // If the result is negative, borrow from the next place
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        list_res.addHead(sub);

        // Move to the previous nodes in each list
        if (ptemp1) ptemp1 = ptemp1->prev;
        if (ptemp2) ptemp2 = ptemp2->prev;
    }

    // Remove any leading zeros from the result list
    while (list_res.getHead() && list_res.getHead()->data == 0 && list_res.getHead() != list_res.getTail()) {
        list_res.removeHead();
    }

    BigInteger result;
    result.list = list_res;
    return result;
}

// ! Addition with long long
BigInteger operator+(long long n, const BigInteger& bi){
    BigInteger temp(n);
    return temp + bi;
}

// ! Subtraction with long long
BigInteger operator-(long long n, const BigInteger& bi){
    BigInteger temp(n);
    return temp - bi;
}
