#include<iostream>
using namespace std;

class Account{
	double balance;
	
	public:
		
		Account(double initialBalance){
			if(initialBalance > 0){
				balance = initialBalance;
			}else{
				balance = 0 ;
				cout << "Your balance is 0.";
			}
		}
		
		void addMoney(double amount){
			if (amount > 0){
				balance += amount;	
			} else {
				cout << "Enter Positive amount.";
			}	
		}
		
		void withdrawMoney(double amount) {
	        if (amount > balance) {
	        	cout << "Withdrawal amount exceeded account balance" <<endl;
	        } else if (amount > 0) {
	            balance -= amount;
	        } else {
	            std::cout << "Withdrawal amount must be positive." << endl;
	        }
    }
		
		double getBalance() const{
			return balance;
		}
};

int main(){
	Account A1(140.0);
	
	cout << "My initial balance is : " << A1.getBalance() << endl;
	
	A1.addMoney(20.0);
	cout << "Balance after adding money is :" << A1.getBalance() << endl;
	
	A1.withdrawMoney(50);
	cout << "Balance after withdrawing money is :" << A1.getBalance() << endl;

	return 0;
}