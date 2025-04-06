#include<iostream>
using namespace std;

class Shape {
	int length, width;

	public:
		Shape(int l, int w) : length(l) , width(w) { }
		
		int Area() const {
			return length * width;
		}
		
		Shape operator+ (const Shape& obj) {
			int totalArea = this->Area() + obj.Area();
			return Shape(totalArea, 1);
		}
		
		void display() const {
        	cout << "Area: " << Area() << endl;
    	}
};

int main() {
	Shape shape1(2,4);
	Shape shape2(4,6);
	
	cout << "Shape 1: " << endl;
	shape1.display();
	
	cout << "\n\nShape 2: " << endl;
	shape2.display();
	
	cout << "\n\nAdded Together: " << endl;
	Shape shape3 = shape1+shape2;
	shape3.display();

	return 0;
}