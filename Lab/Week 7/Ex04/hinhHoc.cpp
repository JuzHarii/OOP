#include "hinhHoc.h"
#include <cmath>
#define PI 3.14159

// ############################################################################################################
// ! Shape implementation
Shape::Shape() {
    area = 0;
    perimeter = 0;
}

double Shape::getArea() {
    return area;
}

double Shape::getPerimeter() {
    return perimeter;
}

// ############################################################################################################
// ! Rectangle implementation
Rectangle::Rectangle() : Shape() {
    width = 0;
    height = 0;
    calcArea();
    calcPerimeter();
}

Rectangle::Rectangle(double w, double h) : Shape() {
    width = (w > 0) ? w : -1 * w;
    height = (h > 0) ? h : -1 * h;
    calcArea();
    calcPerimeter();
}

void Rectangle::input() {
    do {
        cout << "Enter width: ";
        cin >> width;
    } while (width <= 0);

    do {
        cout << "Enter height: ";
        cin >> height;
    } while (height <= 0);

    calcArea();
    calcPerimeter();
}

void Rectangle::calcArea() {
    area = width * height;
}

void Rectangle::calcPerimeter() {
    perimeter = 2 * (width + height);
}

// ############################################################################################################
// ! Circle implementation
Circle::Circle() : Shape() {
    radius = 0;
    calcArea();
    calcPerimeter();
}

Circle::Circle(double r) : Shape() {
    radius = (r > 0) ? r : -1 * r;
    calcArea();
    calcPerimeter();
}

void Circle::input() {
    do {
        cout << "Enter radius: ";
        cin >> radius;
    } while (radius <= 0);

    calcArea();
    calcPerimeter();
}

void Circle::calcArea() {
    area = PI * radius * radius;
}

void Circle::calcPerimeter() {
    perimeter = 2 * PI * radius;
}

// ############################################################################################################
// ! Triangle implementation
Triangle::Triangle() : Shape() {
    base1 = 1;
    base2 = 1;
    base3 = 1;
    calcArea();
    calcPerimeter();
}

Triangle::Triangle(double b1, double b2, double b3) : Shape() {
    base1 = (b1 > 0) ? b1 : -1 * b1;
    base2 = (b2 > 0) ? b2 : -1 * b2;
    base3 = (b3 > 0) ? b3 : -1 * b3;
    calcArea();
    calcPerimeter();
}

void Triangle::input() {
    do {
        cout << "Enter base 1: ";
        cin >> base1;
    } while (base1 <= 0);

    do {
        cout << "Enter base 2: ";
        cin >> base2;
    } while (base2 <= 0);

    do {
        cout << "Enter base 3: ";
        cin >> base3;
    } while (base3 <= 0);

    calcArea();
    calcPerimeter();
}

void Triangle::calcArea() {
    double p = (base1 + base2 + base3) / 2;
    area = sqrt(p * (p - base1) * (p - base2) * (p - base3));
}

void Triangle::calcPerimeter() {
    perimeter = base1 + base2 + base3;
}

// ############################################################################################################
// ! RightTrapezoid implementation
RightTrapezoid::RightTrapezoid() : Shape() {
    base1 = 1;
    base2 = 1;
    height = 1;
    calcArea();
    calcPerimeter();
}

RightTrapezoid::RightTrapezoid(double b1, double b2, double h) : Shape() {
    base1 = (b1 > 0) ? b1 : -1 * b1;
    base2 = (b2 > 0) ? b2 : -1 * b2;
    height = (h > 0) ? h : -1 * h;
    calcArea();
    calcPerimeter();
}

void RightTrapezoid::input() {
    do {
        cout << "Enter base 1: ";
        cin >> base1;
    } while (base1 <= 0);

    do {
        cout << "Enter base 2: ";
        cin >> base2;
    } while (base2 <= 0);

    do {
        cout << "Enter height: ";
        cin >> height;
    } while (height <= 0);

    calcArea();
    calcPerimeter();
}

void RightTrapezoid::calcArea() {
    area = (base1 + base2) * height / 2;
}

void RightTrapezoid::calcPerimeter() {
    perimeter = base1 + base2 + 2 * sqrt(height * height + pow((base2 - base1) / 2, 2));
}

// ############################################################################################################
// ! QuanLyHinhHoc implementation
QuanLyHinhHoc::QuanLyHinhHoc() {
    shapes.clear();
}

QuanLyHinhHoc::~QuanLyHinhHoc() {
    for (auto shape : shapes) {
        delete shape;
    }
    shapes.clear();
}

void QuanLyHinhHoc::addShape(Shape* shape) {
    shapes.push_back(shape);
}

double QuanLyHinhHoc::totalArea() {
    double total = 0;
    for (auto shape : shapes) {
        total += shape->getArea();
    }
    return total;
}

double QuanLyHinhHoc::totalPerimeter() {
    double total = 0;
    for (auto shape : shapes) {
        total += shape->getPerimeter();
    }
    return total;
}
