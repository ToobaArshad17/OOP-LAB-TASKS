#include <iostream>
#include <string>
using namespace std;

class Wallet {
    double balance;
    double daily_limit;
    double daily_deposit;
    double daily_withdrawal;

    public:
        Wallet(double max_daily_limit) {
            balance = 0;
            daily_limit = max_daily_limit;
            daily_deposit = 0;
            daily_withdrawal = 0;
        }

        bool deposit(double amount) {
            if (amount <= 0) {
                cout << "Deposit amount must be positive." << endl;
                return false;
            }
            if (daily_deposit + amount > daily_limit) {
                cout << "Exceeded daily deposit limit!" << endl;
                return false;
            }
            balance += amount;
            daily_deposit += amount;
            cout << "Deposited " << amount << ". Current balance: " << balance << endl;
            return true;
        }

        bool withdraw(double amount) {
            if (amount <= 0) {
                cout << "Withdrawal amount must be positive." << endl;
                return false;
            }
            if (amount > balance) {
                cout << "Insufficient funds!" << endl;
                return false;
            }
            if (daily_withdrawal + amount > daily_limit) {
                cout << "Exceeded daily withdrawal limit!" << endl;
                return false;
            }
            balance -= amount;
            daily_withdrawal += amount;
            cout << "Withdrew " << amount << ". Current balance: " << balance << endl;
            return true;
        }

        double check_balance() const {
            return balance;
        }

        void reset_daily_limits() {
            daily_deposit = 0;
            daily_withdrawal = 0;
        }
};

class User {
    string user_id;
    string name;
    Wallet wallet;

    public:
        User(string id, string user_name, double max_daily_limit)
            : user_id(id), name(user_name), wallet(max_daily_limit) {}

        bool deposit(double amount) {
            return wallet.deposit(amount);
        }

        bool withdraw(double amount) {
            return wallet.withdraw(amount);
        }

        double check_balance() const {
            return wallet.check_balance();
        }
};

int main() {
    User user1("user1", "Alina", 1000);
    User user2("user2", "Babar", 500);

    user1.deposit(500);
    user1.deposit(600);
    user1.withdraw(300);
    user1.withdraw(250);

    user2.deposit(300);
    user2.withdraw(100);
    user2.withdraw(200);

    cout << "User1 balance: " << user1.check_balance() << endl;
    cout << "User2 balance: " << user2.check_balance() << endl;

    return 0;
}