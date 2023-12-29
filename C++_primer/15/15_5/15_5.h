#include <iostream>
#include <string>
#include <fstream>
using namespace std;

static const float PI = 3.14159;
class Shape{
public:
    Shape() = default;
    Shape(const string &n): name(n){}
    virtual double area() = 0; //面积
    virtual double perimeter() = 0; //周长
    virtual ~Shape() = default;
    string getName() const {return name;}
private:
    string name;
};

class Rectangle : public Shape{
public:
    Rectangle() = default;
    Rectangle(const string &n, double w, double h): Shape(n), width(w), height(h){}
    double area() override {return width * height;}
    double perimeter() override {return 2 * (width + height);}
    ~Rectangle() = default;
private:
    double width;
    double height;
};

class Square : public Rectangle{
public:
    Square() = default;
    Square(const string &n, double w): Rectangle(n, w, w){}
    ~Square() = default;

};

class Circle : public Shape{
public:
    Circle() = default;
    Circle(const string &n, double r): Shape(n), radius(r){}
    double area() override {return PI * radius * radius;}
    double perimeter() override {return 2 * PI * radius;}
    ~Circle() = default;
private:
    double radius;
};
