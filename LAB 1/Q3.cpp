#include<iostream>
using namespace std;

int main(){
	int id;
	string name;
	int units;
	float netamount;
	float surcharge;
	float amountcharges;
	
	cout << "Enter name: ";
	cin >> name ;
	
	cout << "Enter customer id: " ;
	cin >> id;
	
	cout << "Enter units consumed: " ;
	cin >> units; 
	
	if(units>0 && units<200){
		amountcharges = units * 16.20;
	}else if(units>199 && units<300){
		amountcharges = units * 20.10;
	}else if(units>299 && units<500){
		amountcharges = units * 27.10;
	}else{
		amountcharges = units * 35.90;
	}
	
	if(amountcharges > 18000){
		surcharge = amountcharges * 0.15;
	}
	
	netamount = surcharge + amountcharges;
	
	cout << "Customer Name: " << name << endl;
	cout << "Customer ID: " << id << endl;
	cout << "Units consumed:" << units << endl;
	cout << "Amount Charges:" << amountcharges << endl;
	cout << "Surcharge Amount: Rs. " << surcharge << endl;
	cout << "Net Amount paid by the customer: Rs. " << netamount << endl;
	
	return 0;

}