#include <iostream>
#include <vector>

using namespace std;

class BasicShape{
protected:
    double area;
public:
    double getArea() const{
        return area;
    }
    virtual void calcArea() = 0;
};

class Circle: public BasicShape{
private:
    double radius;
    long centerX, centerY;
public:
    Circle(double r, long x, long y){
        radius = r;
        centerX = x;
        centerY = y;
        calcArea();
    }
    void calcArea() override{
        area = 3.14159 * radius * radius;
    }
};

class Rectangle: public BasicShape{
private:
    long width, length;
public:
    Rectangle(long w, long l){
        width = w;
        length = l;
        calcArea();
    }
    void calcArea() override {
        area = width * length;
    }
};

class GroupShapes{
private:
    vector<BasicShape*> shapes;
public:
    void add(BasicShape* shape){
        shapes.push_back(shape);
    }
    int totalSum(){
        int sum = 0;
        for(int i = 0; i < shapes.size(); i++){
            sum += shapes[i]->getArea();
        }
        return sum;
    }
    // clone group
    GroupShapes* clone(){
        GroupShapes* newGroup = new GroupShapes();
        // each
    }
};

int main(){
    Circle c(10,5,5);
    Rectangle r(10,5);
    cout << "Circle Area: " << c.getArea() << endl;
    cout << "Rectangle Area: " << r.getArea() << endl;
    cout << "----------------" << endl;
    Circle* pC = new Circle(10, 5, 5);
    Rectangle* pR = new Rectangle(10, 5);
    cout << "Circle area: " << pC->getArea() << endl;
    cout << "Rectangle area: " << pR->getArea() << endl;
    cout << "----------------" << endl;
    GroupShapes group;
    group.add(pC);
    group.add(pR);
    cout << "Total area: " << group.totalSum() << endl;
    return 0;
}