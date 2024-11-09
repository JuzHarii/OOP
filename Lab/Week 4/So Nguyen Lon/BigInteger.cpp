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
    LinkedList list_res;

    Node* ptemp1 = list.getTail();
    Node* ptemp2 = bi.list.getTail();

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

bool BigInteger::operator<=(const BigInteger& bi) {
    LinkedList list_temp = bi.list;

    // Compare lengths first
    if (list.getN() < list_temp.getN())
        return true;
    if (list.getN() > list_temp.getN())
        return false;

    // If lengths are equal, compare digit by digit
    Node* ptemp1 = list.getHead();
    Node* ptemp2 = list_temp.getHead();

    while (ptemp1 && ptemp2) {
        if (ptemp1->data < ptemp2->data)
            return true;
        if (ptemp1->data > ptemp2->data)
            return false;
        ptemp1 = ptemp1->next;
        ptemp2 = ptemp2->next;
    }
    return true;
}


// ! subtraction operator
BigInteger BigInteger::operator-(const BigInteger& bi) {
    BigInteger res;
    if(*this <= bi){
        LinkedList list_res(0);
        res.list = list_res;
        return res;
    }
    
    LinkedList list_temp = bi.list;
    LinkedList list_res;

    Node* ptemp1 = list.getTail();
    Node* ptemp2 = list_temp.getTail();

    int carry = 0;
    while (ptemp1 || ptemp2 || carry) {
        int digit1 = (ptemp1) ? ptemp1->data : 0;
        int digit2 = (ptemp2) ? ptemp2->data : 0;

        int sub = digit1 - digit2 - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        list_res.addHead(sub);

        if (ptemp1) ptemp1 = ptemp1->prev;
        if (ptemp2) ptemp2 = ptemp2->prev;
    }

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


// Multiplication operator
BigInteger BigInteger::operator*(const BigInteger& bi){
    BigInteger result;
    Node* p1 = list.getTail();
    int position = 0;

    while (p1) {
        LinkedList tempList;
        int carry = 0;

        // Add zeros for current position
        for (int i = 0; i < position; i++) {
            tempList.addHead(0);
        }

        Node* p2 = bi.list.getTail();
        while (p2 || carry) {
            int prod = (p1 ? p1->data : 0) * (p2 ? p2->data : 0) + carry;
            tempList.addHead(prod % 10);
            carry = prod / 10;

            if (p2) p2 = p2->prev;
        }

        BigInteger tempResult;
        tempResult.list = tempList;
        result = result + tempResult;
        p1 = p1->prev;
        position++;
    }

    return result;
}

// Multiplication with long long
BigInteger operator*(long long n, const BigInteger& bi){
    BigInteger temp(n);
    return temp * bi;
}