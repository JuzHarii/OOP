#include "Shape.h"

const double PI = 3.14;

Shape::Shape(){
    color = "";
}

Shape::Shape(string color){
    this->color = color;
}
string Shape::getColor(){
    return color;
}

Circle::Circle(){
    radius = 0;
}

Circle::Circle(string color, double radius) : Shape(color){
    this->radius = radius;
}

double Circle::calculateArea(){
    return PI * radius * radius;
}

double Circle::calculatePerimeter(){
    return 2 * PI * radius;
}

Rectangle::Rectangle(){
    length = 0;
    width = 0;
}

Rectangle::Rectangle(string color, double length, double width) : Shape(color){
    this->length = length;
    this->width = width;
}

double Rectangle::calculateArea(){
    return length * width;
}

double Rectangle::calculatePerimeter(){
    return 2 * (length + width);
}