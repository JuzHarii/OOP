#include <iostream>
#include <string>

using namespace std;

class CommissionEmployee{
private:
    string firstName;
    string lastName;
    double grossSales; //tong doanh thu, must > 0
    double commissionRate; // must be > 0 and < 1
public:
    CommissionEmployee();
    CommissionEmployee(string f, string l, double g, double c);
    virtual double earnings() = 0;
    virtual string toString () = 0;

    string getFirstName();
    string getLastName();
    double getGrossSales();
    double getCom();
};

class BasePlusCommissionEmployee : public CommissionEmployee{
private:
    double baseSalary; // must > 500
public:
    BasePlusCommissionEmployee();
    BasePlusCommissionEmployee(string f, string l, double g, double c, double base);
    double earnings();
    string toString();
};