#include "NhanVien.h"
#include <iostream>
using namespace std;

NhanVien::NhanVien(string hoTen, string diaChi, string chungChi, int soLuong)
    : hoTen(hoTen), diaChi(diaChi), chungChi(chungChi), soLuong(soLuong) {}

NhanVien::~NhanVien() {}

void NhanVien::Xuat() const {
    cout << hoTen << " " << "<" << diaChi << "> ";
}

NhanVienThuKy::NhanVienThuKy(string hoTen, string diaChi, string chungChiNgoaiNgu, int soBaoCao)
    : NhanVien(hoTen, diaChi, chungChiNgoaiNgu, soBaoCao) {}

void NhanVienThuKy::Xuat() const {
    NhanVien::Xuat();
    cout << "[NN: " << chungChi << "], bao Cao hoan thanh: " << soLuong;
}

bool NhanVienThuKy::XuatSac() const {
    return soLuong >= 12;  
}

// Lớp NhanVienKyThuat kế thừa từ NhanVien
NhanVienKyThuat::NhanVienKyThuat(string hoTen, string diaChi, string chungChiNganh, int soSangKien)
    : NhanVien(hoTen, diaChi, chungChiNganh, soSangKien) {}

void NhanVienKyThuat::Xuat() const {
    NhanVien::Xuat();
    cout << "[Nganh: " << chungChi << "], sang tao: " << soLuong;
}

bool NhanVienKyThuat::XuatSac() const {
    return soLuong >= 6;
}
