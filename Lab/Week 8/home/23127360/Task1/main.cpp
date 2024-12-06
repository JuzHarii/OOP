#include "Shape.h"
// #include <iomanip>

using namespace std;
int main() {
    string color;
    double radius, width, length;

    // Circle Input
    cout << "Enter color of circle: ";
    cin >> color;
    cout << "Enter radius: ";
    cin >> radius;

    Circle circle(color, radius);

    // Rectangle Input
    cout << "Enter color of rectangle: ";
    cin >> color;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;

    Rectangle rectangle(color, width, length);

    // Circle Output
    cout << "Color of Circle: " << circle.getColor() << endl;
    cout << "Area of Circle: " << circle.calculateArea() << endl;
    cout << "Perimeter of Circle: " << circle.calculatePerimeter() << endl;

    // Rectangle Output
    cout << "Color of Rectangle: " << rectangle.getColor() << endl;
    cout << "Area of Rectangle: " << rectangle.calculateArea() << endl;
    cout << "Perimeter of Rectangle: " << rectangle.calculatePerimeter() << endl;

    return 0;
}