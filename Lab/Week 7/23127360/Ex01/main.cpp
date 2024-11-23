#include "phanSo.h"

int main() {
    PS1 a, b, c;
    cout << "Nhap phan so a (tu va mau): " << endl;
    a.input();
    cout << "Nhap phan so b (tu va mau): " << endl;
    b.input();

    c = a + b;
    cout << "Tong cua a va b: ";
    c.display();

    PS2 ps1, ps2;
    cout << "Nhap phan so thu nhat (tu va mau): " << endl;
    cin >> ps1;
    cout << "Nhap phan so thu hai (tu va mau): " << endl;
    cin >> ps2;

    cout << "Phan so 1: " << ps1 << endl;
    cout << "Phan so 2: " << ps2 << endl;

    if (ps1 == ps2) {
        cout << "Hai phan so bang nhau" << endl;
    } else {
        cout << "Hai phan so khac nhau" << endl;
        if (ps1 > ps2) {
            cout << "Phan so 1 lon hon phan so 2" << endl;
        } else {
            cout << "Phan so 1 nho hon phan so 2" << endl;
        }
    }

    return 0;
}
