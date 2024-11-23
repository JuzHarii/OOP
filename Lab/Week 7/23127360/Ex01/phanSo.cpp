#include "phanSo.h"

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

PS1::PS1() : tu(0), mau(1) {}

void PS1::input() {
    std::cout << "Nhap tu so: ";
    std::cin >> tu;
    std::cout << "Nhap mau so (khac 0): ";
    std::cin >> mau;
    while (mau == 0) {
        std::cout << "Mau so khong duoc bang 0. Nhap lai: ";
        std::cin >> mau;
    }
    simplify();
}

void PS1::simplify() {
    int gcdValue = gcd(tu, mau);
    tu /= gcdValue;
    mau /= gcdValue;
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

PS1 PS1::operator+(const PS1& other) {
    PS1 result;
    result.tu = tu * other.mau + other.tu * mau;
    result.mau = mau * other.mau;
    result.simplify();
    return result;
}

void PS1::display() const {
    if (mau == 1) {
        std::cout << tu << std::endl;
    } else {
        std::cout << tu << "/" << mau << std::endl;
    }
}

PS2::PS2() : PS1(), sign(1) {}

std::istream& operator>>(std::istream& is, PS2& ps) {
    is >> ps.tu >> ps.mau;
    if (ps.mau == 0) {
        ps.mau = 1;
        std::cerr << "Warning: Mau so khong duoc bang 0. Defaulting to 1.\n";
    }
    ps.sign = (ps.tu * ps.mau < 0) ? -1 : 1;
    ps.tu = abs(ps.tu);
    ps.mau = abs(ps.mau);
    ps.simplify();
    return is;
}

std::ostream& operator<<(std::ostream& os, const PS2& ps) {
    if (ps.sign < 0) os << "-";
    if (ps.mau == 1) {
        os << ps.tu;
    } else {
        os << ps.tu << "/" << ps.mau;
    }
    return os;
}

PS2 PS2::operator-(const PS2& other) {
    PS2 result;
    result.tu = (sign * tu) * other.mau - (other.sign * other.tu) * mau;
    result.mau = mau * other.mau;
    result.sign = (result.tu < 0) ? -1 : 1;
    result.tu = abs(result.tu);
    result.simplify();
    return result;
}

PS2 PS2::operator*(const PS2& other) {
    PS2 result;
    result.tu = tu * other.tu;
    result.mau = mau * other.mau;
    result.sign = sign * other.sign;
    result.simplify();
    return result;
}

PS2 PS2::operator/(const PS2& other) {
    PS2 result;
    result.tu = tu * other.mau;
    result.mau = mau * other.tu;
    result.sign = sign * other.sign;
    result.simplify();
    return result;
}

bool PS2::operator==(const PS2& other) const {
    return tu == other.tu && mau == other.mau && sign == other.sign;
}

bool PS2::operator!=(const PS2& other) const {
    return !(*this == other);
}

bool PS2::operator<(const PS2& other) const {
    return (sign * tu * other.mau) < (other.sign * other.tu * mau);
}

bool PS2::operator<=(const PS2& other) const {
    return (*this < other || *this == other);
}

bool PS2::operator>(const PS2& other) const {
    return !(*this <= other);
}

bool PS2::operator>=(const PS2& other) const {
    return !(*this < other);
}

PS2& PS2::operator++() {
    tu += mau;
    simplify();
    return *this;
}

PS2& PS2::operator--() {
    tu -= mau;
    simplify();
    return *this;
}
