#include <iostream>
#include <iomanip>                
using namespace std;

class BankAccount {           
    public:
        int accountNum;
        double balance;

    public:
        BankAccount(int an, double b) : accountNum(an), balance(b) {}

        virtual void displayBalance() {
            cout << fixed << setprecision(2);
            cout << "Account Number: " << accountNum << " | Balance: " << balance << endl;
        }

        virtual void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        }

        virtual void withdraw(double amount) {
            if (amount > balance) {
                cout << "Insufficient funds! Withdrawal denied." << endl;
            } else {
                balance -= amount;
                cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
            }
        }

    virtual ~BankAccount() {} 
};

class SavingAccount : public BankAccount {
    public:
        SavingAccount(int an, double b) : BankAccount(an, b) {}

        void monthlyInterest() {
            double interest = balance * 0.05;
            balance += interest;
            cout << "Interest: " << interest << " | New Balance: " << balance << endl;
        }
};

class CheckingAccount : public BankAccount {
    public:
        CheckingAccount(int an, double b) : BankAccount(an, b) {}

        void withdraw(double amount) override {
            if (amount > balance) {
                cout << "Overdraft alert! Cannot withdraw " << amount << ". Insufficient funds!" << endl;
            } else {
                balance -= amount;
                cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
            }
        }
};

class BusinessAccount : public BankAccount {
    public:
        BusinessAccount(int an, double b) : BankAccount(an, b) {}

        void deposit(double amount) override {
            double tax = amount * 0.15;
            double netDeposit = amount - tax;
            balance += netDeposit;
            cout << "Deposited: " << amount << " | Tax: " << tax << " | New Balance: " << balance << endl;
        }
};

class Employee {        
    protected:
        int ID;
        string name;
        string role;

    public:
        Employee(int id, string n, string r) : ID(id), name(n), role(r) {}

        virtual void display() {
            cout << "Employee: " << name << " | ID: " << ID << " | Role: " << role << endl;
        }

        virtual ~Employee() {}         
    };

class Teller : public Employee {
    public:
        Teller(int id, string n) : Employee(id, n, "Teller") {}

        void deposit(BankAccount* account, double amount) {
            account->deposit(amount);
        }

        void withdraw(BankAccount* account, double amount) {
            account->withdraw(amount);
        }

        void freeze() {
            cout << "Account has been frozen!" << endl;
        }
};

class Manager : public Employee {
    public:
        Manager(int id, string n) : Employee(id, n, "Manager") {}

        void overrideLimits(BankAccount* account, double newBalance) {
            account->deposit(newBalance - account->balance);
            cout << "Manager adjusted account balance. New Balance: " << newBalance << endl;
        }
};

class Customer {
        int ID;
        string name;

    public:
        Customer(int id, string n) : ID(id), name(n) {}

        void deposit(BankAccount* account, double amount) {
            account->deposit(amount);
        }

        void withdraw(BankAccount* account, double amount) {
            account->withdraw(amount);
        }

        void display() {
            cout << "Customer: " << name << " | ID: " << ID << endl;
        }
};

int main() {
    cout << "SAVINGS ACCOUNT" << endl;
    SavingAccount save(1224, 345678);
    save.displayBalance();
    save.monthlyInterest();

    cout << endl;

    cout << "CHECKING ACCOUNT" << endl;
    CheckingAccount check(1225, 5000);
    check.displayBalance();
    check.withdraw(6000); 
    check.withdraw(4000);       

    cout << endl;

    cout << "BUSINESS ACCOUNT" << endl;
    BusinessAccount business(1226, 10000);
    business.deposit(2000);

    cout << endl;

    cout << "CUSTOMER" << endl;
    Customer customer(234, "Sara Ali");
    customer.display();
    customer.deposit(&save, 500);
    customer.withdraw(&save, 200);

    cout << endl;

    cout << "TELLER" << endl;
    Teller teller(34, "Aliza");
    teller.display();
    teller.withdraw(&save, 1000);
    teller.freeze();

    cout << endl;

    cout << "MANAGER" << endl;
    Manager manager(12, "Aliyan Ali");
    manager.display();
    manager.overrideLimits(&save, 500000); 

    return 0;
}