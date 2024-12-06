#include "header.h"

int main(){
    string f, l;
    double g, c, base;
    cout << "Enter first name: ";
    cin.ignore();
    getline(cin, f);
    cout << "Enter last name: ";
    getline(cin, l);
    cout << "Enter gross sales: ";
    cin >> g;
    cout << "Enter commission rate: ";
    cin >> c;
    cout << "Enter base salary: ";
    cin >> base;
    BasePlusCommissionEmployee chillGuy(f, l, g, c, base);
    cout << "Employee Details (BasePlusCommissionEmployee) :" << endl;
    cout << chillGuy.toString() << endl;
    return 0;
}