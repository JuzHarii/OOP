#include <iostream>
#include <cmath>

using namespace std;

class SP1 {
protected:
    double phanThuc;
    double phanAo;
public:
    SP1();
    void input();
    void display();
    
};

class SP2 : public SP1{
public:
    SP2();
    double module();
    
    friend ostream& operator<<(ostream& os, const SP2& sp);
    friend istream& operator>>(istream& is, SP2& sp);
    
    SP2 operator+(SP2);
    SP2 operator-(SP2);
    SP2 operator*(SP2);
    SP2 operator/(SP2);

    bool operator==(SP2);
    bool operator!=(SP2);
    bool operator>(SP2);
    bool operator<(SP2);
    bool operator>=(SP2);
    bool operator<=(SP2);

    SP2 operator++(int);
    SP2 operator--(int);
    SP2 operator++();
    SP2 operator--();
};