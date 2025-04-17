#include <iostream>
using namespace std;

class Shape{
    public:
        virtual double getArea() = 0 ;
        virtual ~Shape() {}
};

class Rectangle : public Shape{
    double length , width;

    public:
        Rectangle(double l, double w) : length(l), width(w) {}

        double getArea() override {
            return length * width;
        }
};

class Triangle : public Shape{
    double height , base;

    public:
        Triangle(double b, double h) : base(b), height(h) {}

        double getArea() override {
            return (height * base) / 2;
        }
};

int main(){
    Shape *S1 = new Rectangle(10,7);
    Shape *S2;
    Triangle T(2,4);
    S2=&T;

    cout << "Area of rectangle:" << S1->getArea() << endl;
    cout << "Area of triangle:" << S2->getArea() << endl;

    return 0;
}