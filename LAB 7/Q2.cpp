#include <iostream>

using namespace std;

class Shape {
protected:
    double positionX;
    double positionY;
    string color;
    double borderThickness;

public:
    // Constructor to initialize common properties
    Shape(double x, double y, string col, double thickness = 1.0)
        : positionX(x), positionY(y), color(col), borderThickness(thickness) {}

    // Virtual methods to be overridden by derived classes
    virtual void draw() = 0;  // Pure virtual function for drawing the shape
    virtual double calculateArea() = 0;  // Pure virtual function for calculating area
    virtual double calculatePerimeter() = 0;  // Pure virtual function for calculating perimeter
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double x, double y, string col, double r, double thickness = 1.0)
        : Shape(x, y, col, thickness), radius(r) {}

    void draw() override {
        cout << "Drawing Circle at (" << positionX << ", " << positionY << ") with color " << color << endl;
    }

    double calculateArea() override {
        return 3.142 * radius * radius;  // Area of Circle: pr^2
    }

    double calculatePerimeter() override {
        return 2 * 3.142 * radius;  // Perimeter of Circle: 2pr
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    double topLeftX;
    double topLeftY;

public:
    Rectangle(double x, double y, string col, double w, double h, double tLeftX, double tLeftY, double thickness = 1.0)
        : Shape(x, y, col, thickness), width(w), height(h), topLeftX(tLeftX), topLeftY(tLeftY) {}

    void draw() override {
        cout << "Drawing Rectangle at (" << positionX << ", " << positionY << ") with color " << color << endl;
    }

    double calculateArea() override {
        return width * height;  // Area of Rectangle: width * height
    }

    double calculatePerimeter() override {
        return 2 * (width + height);  // Perimeter of Rectangle: 2 * (width + height)
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double x, double y, string col, double b, double h, double thickness = 1.0)
        : Shape(x, y, col, thickness), base(b), height(h) {}

    void draw() override {
        cout << "Drawing Triangle at (" << positionX << ", " << positionY << ") with color " << color << endl;
    }

    double calculateArea() override {
        return 0.5 * base * height;  // Area of Triangle: 1/2 * base * height
    }

    double calculatePerimeter() override {
        // Assuming it is an equilateral triangle for simplicity
        return 3 * base;  // Perimeter of Equilateral Triangle: 3 * base
    }
};

class Polygon : public Shape {
private:
    int numberOfSides;
    double sideLength;

public:
    Polygon(double x, double y, string col, int sides, double length, double thickness = 1.0)
        : Shape(x, y, col, thickness), numberOfSides(sides), sideLength(length) {}

    void draw() override {
        cout << "Drawing Polygon at (" << positionX << ", " << positionY << ") with color " << color << endl;
    }

    double calculateArea() override {
        return (numberOfSides * sideLength * sideLength) / (4 * tan(3.142 / numberOfSides));
    }

    double calculatePerimeter() override {
        return numberOfSides * sideLength;  // Perimeter of Polygon: numberOfSides * sideLength
    }
};

int main() {
    // Create instances of different shapes
    Circle circle(10, 20, "Red", 5);
    Rectangle rectangle(15, 25, "Blue", 10, 20, 5, 5);
    Triangle triangle(20, 30, "Green", 6, 8);
    Polygon polygon(30, 40, "Yellow", 5, 8);

    // Draw the shapes
    circle.draw();
    rectangle.draw();
    triangle.draw();
    polygon.draw();

    // Calculate and display areas
    cout << "Area of Circle: " << circle.calculateArea() << endl;
    cout << "Area of Rectangle: " << rectangle.calculateArea() << endl;
    cout << "Area of Triangle: " << triangle.calculateArea() << endl;
    cout << "Area of Polygon: " << polygon.calculateArea() << endl;

    // Calculate and display perimeters
    cout << "Perimeter of Circle: " << circle.calculatePerimeter() << endl;
    cout << "Perimeter of Rectangle: " << rectangle.calculatePerimeter() << endl;
    cout << "Perimeter of Triangle: " << triangle.calculatePerimeter() << endl;
    cout << "Perimeter of Polygon: " << polygon.calculatePerimeter() << endl;

    return 0;
}

