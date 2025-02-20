#include<iostream>
using namespace std;

class Circle{
	double radius;
	
	public:
		Circle(double r){
			radius = r;
		}
		
		double getArea() const {
			return 3.142 * radius * radius;
		}
		
		double getPerimeter() const {
        return 2 * 3.142 * radius;
    }
};

int main(){
	Circle c(8.0);
	
	cout << "Area Of Circle Is: " << c.getArea() <<endl;
	cout << "Perimeter Of Circle Is: " << c.getPerimeter() <<endl;
	
	return 0;
}