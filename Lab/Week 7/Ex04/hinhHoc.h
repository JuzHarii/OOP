#include <iostream>
#include <vector>

using namespace std;

// ! Shape
class Shape{
protected:
    double area;
    double perimeter;
public:
    Shape();
    virtual void input() = 0; // pure virtual function
    virtual void calcArea() = 0; // pure virtual function
    virtual void calcPerimeter() = 0; // pure virtual function
    double getArea();
    double getPerimeter();
};

// ! Rectangle
class Rectangle: public Shape{
private:
    double width, height;
public:
    Rectangle();
    Rectangle(double w, double h);

    double getWidth(){
        return width;
    }
    double getHeight(){
        return height;
    }
    void input();
    void calcArea();
    void calcPerimeter();
};

// ! Circle
class Circle: public Shape{
private:
    double radius;
public:
    Circle();
    Circle(double r);
    void input();
    void calcArea();
    void calcPerimeter();

};
// ! Triangle
class Triangle: public Shape{
private:
    double base1, base2, base3;
public:
    Triangle();
    Triangle(double b1, double b2, double b3);
    void input();
    void calcArea();
    void calcPerimeter();

};
// ! RightTrapezoid
class RightTrapezoid: public Shape{
private:
    double base1, base2, height;
public:
    RightTrapezoid();
    RightTrapezoid(double b1, double b2, double h);
    void input();
    void calcArea();
    void calcPerimeter();

};

class QuanLyHinhHoc{
private:
    vector<Shape*> shapes;
public:
    QuanLyHinhHoc();
    ~QuanLyHinhHoc();
    void addShape(Shape* shape);
    double totalArea();
    double totalPerimeter();
};