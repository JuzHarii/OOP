#include "header.h"

CommissionEmployee::CommissionEmployee(){
    this->firstName = "";
    this->lastName = "";
    this->grossSales = 1;             // default
    this->commissionRate = 0.5;       // default
}

CommissionEmployee::CommissionEmployee(string f, string l, double g, double c){
    this->firstName = f;
    this->lastName = l;
    g = (g > 0) ? g : 1; 
    c = (c > 0 && c < 1) ? c : 0.5;
    this->grossSales = g;
    this->commissionRate = c;
}

string CommissionEmployee::getFirstName(){
    return this->firstName;
}

string CommissionEmployee::getLastName(){
    return this->lastName;
}

double CommissionEmployee::getGrossSales(){
    return this->grossSales;
}

double CommissionEmployee::getCom(){
    return this->commissionRate;
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee() : CommissionEmployee() {
    baseSalary = 501;
}


BasePlusCommissionEmployee::BasePlusCommissionEmployee(string f, string l, double g, double c, double base) : CommissionEmployee(f, l, g, c) {
    if(base < 501){
        cout << "Base salary must be greater than 500, automatically set base at 501" << endl;
        base = 501;
    } 
    baseSalary = base;
}

double BasePlusCommissionEmployee::earnings(){
    return this->getGrossSales() * this->getCom() * baseSalary;
}

string BasePlusCommissionEmployee::toString(){
    return "Name: " + this->getFirstName() + " " + this->getLastName() + "\nGross Sales: " + to_string(this->getGrossSales()) + "\nCommission Rate: " + to_string(this->getCom()) + "\nBase Salary: " + to_string(baseSalary) + "\nEarnings: " + to_string(this->earnings());
}


