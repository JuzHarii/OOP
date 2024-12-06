#include <iostream>

using namespace std;

class Shape{
private:
    string color;
public:
    Shape();
    Shape(string color);
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    string getColor();
};

class Circle : public Shape{
private:
    double radius;
public:
    Circle();
    Circle(string color, double radius);
    double calculateArea();
    double calculatePerimeter();
};


class Rectangle : public Shape{
private:
    double length;
    double width;
public:
    Rectangle();
    Rectangle(string color, double length, double width);
    double calculateArea();
    double calculatePerimeter();
};