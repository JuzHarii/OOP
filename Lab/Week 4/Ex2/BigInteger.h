#include "Linked_List.cpp"

class BigInteger{
private:
    LinkedList list;
public:
    // ! constructors
    BigInteger();
    BigInteger(long long n);
    BigInteger(int x, int n);

    // ! operators
    BigInteger operator+(const BigInteger& bi);
    BigInteger operator-(const BigInteger& bi);
    BigInteger operator*(const BigInteger& bi);

    // ! friend function
    friend BigInteger operator+(long long n, const BigInteger& bi);
    friend BigInteger operator-(long long n, const BigInteger& bi);
    friend BigInteger operator*(long long n, const BigInteger& bi);

    // ! friend ostream
    friend ostream& operator<<(ostream& os, const BigInteger& bi);
};
