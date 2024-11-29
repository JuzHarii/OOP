#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;


class NhanVien {
protected:
    string hoTen;
    string diaChi;
    string chungChi;  
    int soLuong;      

public:
    NhanVien(string hoTen, string diaChi, string chungChi, int soLuong);
    virtual ~NhanVien();

    virtual void Xuat() const;
    virtual bool XuatSac() const = 0;
};


class NhanVienThuKy : public NhanVien {
public:
    NhanVienThuKy(string hoTen, string diaChi, string chungChiNgoaiNgu, int soBaoCao);
    void Xuat() const override;
    bool XuatSac() const override;
};


class NhanVienKyThuat : public NhanVien {
public:
    NhanVienKyThuat(string hoTen, string diaChi, string chungChiNganh, int soSangKien);
    void Xuat() const override;
    bool XuatSac() const override;
};

#endif
