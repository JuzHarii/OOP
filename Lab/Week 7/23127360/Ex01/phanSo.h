#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b);

class PS1 {
protected:
    int tu;
    int mau;

public:
    PS1();
    void input();
    void simplify();
    PS1 operator+(const PS1& other);
    void display() const;
};

class PS2 : public PS1 {
private:
    int sign;

public:
    PS2();
    friend std::istream& operator>>(std::istream& is, PS2& ps);
    friend std::ostream& operator<<(std::ostream& os, const PS2& ps);
    PS2 operator-(const PS2& other);
    PS2 operator*(const PS2& other);
    PS2 operator/(const PS2& other);
    bool operator==(const PS2& other) const;
    bool operator!=(const PS2& other) const;
    bool operator<(const PS2& other) const;
    bool operator<=(const PS2& other) const;
    bool operator>(const PS2& other) const;
    bool operator>=(const PS2& other) const;
    PS2& operator++();
    PS2& operator--();
};