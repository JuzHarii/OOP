#include "hinhHoc.h"

int main() 
{ 
    QuanLyHinhHoc ql; 
    ql.addShape(new Rectangle(5.6, 2.3)); 
    ql.addShape(new Triangle(-1.5, 6.7, 5.9)); 
    ql.addShape(new Circle(12.7)); 
    ql.addShape(new RightTrapezoid(10.1, 8.6, 3.5)); 
    
    cout << "Tong Dien tich: " << ql.totalArea() << endl; 
    cout << "Tong Chu vi: " << ql.totalPerimeter() << endl; 
    cout << endl << endl; 
    return 0;
}