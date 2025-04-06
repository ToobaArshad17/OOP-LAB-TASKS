#include<iostream>
using namespace std;

class Test {
	int num;
	public:
		Test(int n) : num(n) {}  // parameterized constructor
		
		Test& operator-- () {  // prefix
			num *= 4;
			return *this;
		}
		
		Test operator -- (int) {  // postfix
			Test temp = *this;
			num /= 4;
			return temp;
		}
		
		void display() const{
			cout << num;
		}
};
int main() {
	Test test(4);
	
	cout << "Original value: ";
	test.display();
	
	--test;
	cout << "\n\nprefix (multiplied by 4): ";
	test.display();
	
	test--;
	cout << "\n\npostfix (divided by 4): ";
	test.display();
	return 0;
}