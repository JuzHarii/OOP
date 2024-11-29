#ifndef CONGTY_H
#define CONGTY_H

#include <vector>
#include "NhanVien.h"

class CongTy {
private:
    vector<NhanVien*> danhSachNV;

public:
    void ThemNhanVien(NhanVien* nv);
    void DanhSachNV(ostream& out) const;
    void DanhSachNVXuatSac(ostream& out) const;
    ~CongTy();
};

#endif
