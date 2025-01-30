#include<iostream>
using namespace std;

int main(){
	int numofelements;
	float arr[numofelements];
	float *ptr = arr;
	
	float sum = 0;
	
	cout << "Enter the Num of elements in the array: " << endl;
	cin >> numofelements ;
	
	cout << "The elements are: "<< endl;
	for (int i=0; i<numofelements; i++){
		cin >> *(ptr + i);
		sum += *(ptr+i);
	}
	
	cout << "The Sum of elements is: " << sum ;
	
}