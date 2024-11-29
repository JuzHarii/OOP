#include <string>
#include <iostream>

using namespace std;

class NGUOI {
protected:
    string hoTen;
    string ngaySinh;
    string diaChi;

public:
    NGUOI();
    NGUOI(string hoTen, string ngaySinh, string diaChi);

    virtual void input();
    virtual void display() const;
};

class NV : public NGUOI {
private:
    string department;
    double salaryIndex;
    double allowance;

public:
    NV();
    
    void input() override;
    void display() const override;
};