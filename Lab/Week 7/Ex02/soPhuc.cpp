#include "soPhuc.h"

SP1::SP1() {
    phanThuc = 0;
    phanAo = 0;
}

void SP1::input() {
    cout << "Nhap phan thuc: ";
    cin >> phanThuc;
    cout << "Nhap phan ao: ";
    cin >> phanAo;
}

void SP1::display() {
    cout << phanThuc;
    if(phanAo >= 0) {
        cout << " + " << phanAo << "i";
    } else {
        cout << " - " << -phanAo << "i";
    }
}


SP2::SP2() : SP1() {
}

double SP2::module() {
    return sqrt(phanThuc * phanThuc + phanAo * phanAo);
}

ostream& operator<<(ostream& os, const SP2& sp) {
    os << sp.phanThuc;
    if(sp.phanAo >= 0) {
        os << " + " << sp.phanAo << "i";
    } else {
        os << " - " << -sp.phanAo << "i";
    }
    return os;
}

istream& operator>>(istream& is, SP2& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.phanThuc;
    cout << "Nhap phan ao: ";
    is >> sp.phanAo;
    return is;
}

SP2 SP2::operator+(SP2 sp) {
    SP2 temp;
    temp.phanThuc = phanThuc + sp.phanThuc;
    temp.phanAo = phanAo + sp.phanAo;
    return temp;
}

SP2 SP2::operator-(SP2 sp){
    SP2 temp;
    temp.phanThuc = phanThuc - sp.phanThuc;
    temp.phanAo = phanAo - sp.phanAo;
    return temp;
}

// z1 = a + bi và z2 = c + di 
// z1.z2 = (ac - bd) + (ad + bc)i

SP2 SP2::operator*(SP2 sp){
    SP2 temp;
    temp.phanThuc = phanThuc * sp.phanThuc - phanAo * sp.phanAo; 
    temp.phanAo = phanThuc * sp.phanAo + phanAo * sp.phanThuc;
    return temp;
}
// z1 / z2 = (ac + bd) / (c^2 + d^2) + (bc - ad) / (c^2 + d^2)i
SP2 SP2::operator/(SP2 sp){
    SP2 temp;
    temp.phanThuc = (phanThuc * sp.phanThuc + phanAo * sp.phanAo) / (sp.phanThuc * sp.phanThuc + sp.phanAo * sp.phanAo);
    temp.phanAo = (phanAo * sp.phanThuc - phanThuc * sp.phanAo) / (sp.phanThuc * sp.phanThuc + sp.phanAo * sp.phanAo);
    return temp;
}

bool SP2::operator==(SP2 sp){
    return phanThuc == sp.phanThuc && phanAo == sp.phanAo;
}

bool SP2::operator!=(SP2 sp){
    return !(*this == sp);
}

bool SP2::operator>(SP2 sp){
    return this->module() > sp.module();
}

bool SP2::operator<(SP2 sp){
    return this->module() < sp.module();
}
bool SP2::operator>=(SP2 sp){
    return this->module() >= sp.module();
}
bool SP2::operator<=(SP2 sp){
    return this->module() <= sp.module();
}

SP2 SP2::operator++(int){
    SP2 temp = *this;
    phanThuc++;
    return temp;
}
SP2 SP2::operator--(int){
    SP2 temp = *this;
    phanThuc--;
    return temp;
}

SP2 SP2::operator++(){
    phanThuc++;
    return *this;
}
SP2 SP2::operator--(){
    phanThuc--;
    return *this;
}