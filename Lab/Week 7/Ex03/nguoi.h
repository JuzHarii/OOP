#include <iostream>

using namespace std;

class NGUOI{
private:
    string hoTen;
    string ngaySinh;
    string diaChi;
public:
    NGUOI();
    NGUOI(string hoTen, string ngaySinh, string diaChi);
    void input();
    void display();
    ~NGUOI();
};