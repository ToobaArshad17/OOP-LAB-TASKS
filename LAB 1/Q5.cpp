#include<iostream>
#include <iomanip>
using namespace std;

int main(){
	string name;
	int adultTickets , childTickets ,totalTickets;
	float adultTicketPrice, childTicketPrice ;
	float donationPercentage ;
	float grossamount , amountdonated ,  netsale;
	
	
	cout << "Enter Movie name: ";
	cin >> name;
	
	cout << "Enter adult ticket price: $";
    cin >> adultTicketPrice;
    
    cout << "Enter child ticket price: $";
    cin >> childTicketPrice;
    
    cout << "Enter number of adult tickets that are sold: ";
    cin >> adultTickets;
    
    cout << "Enter number of child tickets that are sold: ";
    cin >> childTickets;
    
    cout << "Enter the donation percentage: ";
    cin >> donationPercentage;
    
    totalTickets = childTickets + adultTickets;
    
    grossamount = (adultTicketPrice * adultTickets) + (childTicketPrice * childTickets);
    amountdonated = grossamount * (donationPercentage / 100);
    netsale = grossamount - amountdonated;
    
     cout << fixed << setprecision(2);
    
    cout << "\n_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n";
    cout << "Movie Name: " << left << setw(40) << name << endl;
    cout << "Number of Tickets Sold: " << right << setw(10) << totalTickets << endl;
    cout << "Gross Amount: $" << right << setw(12) << grossamount << endl;
    cout << "Percentage of Gross Amount Donated: " << right << setw(8) << donationPercentage << "%" << endl;
    cout << "Amount Donated: $" << right << setw(12) << amountdonated << endl;
    cout << "Net Sale: $" << right << setw(15) << netsale << endl;
    
    return 0;
    
    
}