#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    string transactionHistory[10];  // Array to store transaction history (limit to 10 transactions)
    int transactionCount;

public:
    Account(string accountNum, double initialBalance, string holderName, string type = "Savings")
        : accountNumber(accountNum), balance(initialBalance), accountHolderName(holderName), accountType(type), transactionCount(0) {}

    // Deposit function to add funds to the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            if (transactionCount < 10) {
                transactionHistory[transactionCount++] = "Deposited: " + to_string(amount);
            } else {
                for (int i = 1; i < 10; ++i) {
                    transactionHistory[i - 1] = transactionHistory[i];
                }
                transactionHistory[9] = "Deposited: " + to_string(amount);
            }
        } else {
            cout << "Error: Deposit amount must be positive." << endl;
        }
    }

    // Withdraw function to remove funds from the account
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive." << endl;
        } else if (amount > balance) {
            cout << "Error: Insufficient balance." << endl;
        } else {
            balance -= amount;
            if (transactionCount < 10) {
                transactionHistory[transactionCount++] = "Withdrew: " + to_string(amount);
            } else {
                for (int i = 1; i < 10; ++i) {
                    transactionHistory[i - 1] = transactionHistory[i];
                }
                transactionHistory[9] = "Withdrew: " + to_string(amount);
            }
        }
    }

    virtual void calculateInterest() {
        double interest = balance * 0.05;  // 5% interest rate as default
        balance += interest;
        if (transactionCount < 10) {
            transactionHistory[transactionCount++] = "Interest added: " + to_string(interest);
        } else {
            for (int i = 1; i < 10; ++i) {
                transactionHistory[i - 1] = transactionHistory[i];
            }
            transactionHistory[9] = "Interest added: " + to_string(interest);
        }
    }

    void printStatement() {
        cout << "Transaction History for Account: " << accountNumber << endl;
        for (int i = 0; i < transactionCount; ++i) {
            cout << transactionHistory[i] << endl;
        }
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        printf("Balance: %.2f\n", balance);
    }
};


class CheckingAccount : public Account {
public:
    CheckingAccount(string accountNum, double initialBalance, string holderName)
        : Account(accountNum, initialBalance, holderName, "Checking") {}

    // Overriding calculateInterest for checking accounts (example: no interest)
    void calculateInterest() override {
        cout << "No interest for Checking Account." << endl;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string accountNum, double initialBalance, string holderName)
        : Account(accountNum, initialBalance, holderName, "Savings") {}

    // Overriding calculateInterest for savings accounts (higher interest rate)
    void calculateInterest() override {
        double interest = balance * 0.08;  // 8% interest for savings account
        balance += interest;
        if (transactionCount < 10) {
            transactionHistory[transactionCount++] = "Interest added: " + to_string(interest);
        } else {
            for (int i = 1; i < 10; ++i) {
                transactionHistory[i - 1] = transactionHistory[i];
            }
            transactionHistory[9] = "Interest added: " + to_string(interest);
        }
    }
};

int main() {
    // Create an instance of SavingsAccount and CheckingAccount
    SavingsAccount savings("S12345", 1000.0, "John Doe");
    CheckingAccount checking("C67890", 500.0, "Jane Smith");

    // Perform some operations on savings account
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateInterest();
    savings.printStatement();

    cout << endl;

    // Perform some operations on checking account
    checking.deposit(300.0);
    checking.withdraw(100.0);
    checking.calculateInterest();  // No interest for CheckingAccount
    checking.printStatement();

    // Get account information
    cout << endl;
    savings.getAccountInfo();
    cout << endl;
    checking.getAccountInfo();

    return 0;
}

