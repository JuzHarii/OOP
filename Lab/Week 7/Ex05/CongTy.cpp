#include "CongTy.h"
#include <iostream>
using namespace std;

void CongTy::ThemNhanVien(NhanVien* nv) {
    danhSachNV.push_back(nv);
}

void CongTy::DanhSachNV(ostream& out) const {
    for (const auto& nv : danhSachNV) {
        nv->Xuat();
        out << endl;
    }
}

void CongTy::DanhSachNVXuatSac(ostream& out) const {
    for (const auto& nv : danhSachNV) {
        if (nv->XuatSac()) {
            nv->Xuat();
            out << endl;
        }
    }
}

CongTy::~CongTy() {
    for (auto nv : danhSachNV) {
        delete nv;
    }
}
