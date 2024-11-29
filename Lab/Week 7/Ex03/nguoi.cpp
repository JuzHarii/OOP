#include "nguoi.h"

using namespace std;

// NGUOI class implementation
NGUOI::NGUOI() : hoTen(""), ngaySinh(""), diaChi("") {}

NGUOI::NGUOI(string hoTen, string ngaySinh, string diaChi)
    : hoTen(hoTen), ngaySinh(ngaySinh), diaChi(diaChi) {}

void NGUOI::input() {
    cout << "Nhap ho ten: ";
    cin.ignore(); // Ensure input buffer is cleared
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

void NGUOI::display() const {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Dia chi: " << diaChi << endl;
}

// NV class implementation
NV::NV() : NGUOI(), department(""), salaryIndex(0), allowance(0) {}

void NV::input() {
    NGUOI::input();
    cout << "Nhap phong ban: ";
    getline(cin, department);

    cout << "Nhap he so luong: ";
    do {
        cin >> salaryIndex;
        if (salaryIndex <= 0) {
            cout << "He so luong phai lon hon 0. Vui long nhap lai: ";
        }
    } while (salaryIndex <= 0);

    cout << "Nhap phu cap: ";
    do {
        cin >> allowance;
        if (allowance < 0) {
            cout << "Phu cap phai lon hon hoac bang 0. Vui long nhap lai: ";
        }
    } while (allowance < 0);
}


void NV::display() const {
    NGUOI::display();
    cout << "Phong ban: " << department << endl;
    cout << "He so luong: " << salaryIndex << endl;
    cout << "Phu cap: " << allowance << endl;
}
