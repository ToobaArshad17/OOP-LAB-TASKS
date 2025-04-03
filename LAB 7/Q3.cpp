#include <iostream>
#include <string>

using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    // Constructor to initialize currency details
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    // Convert to a common base currency (assumed to be USD for simplicity)
    double convertToBase() {
        return amount * exchangeRate;  // Convert based on the exchange rate to the base currency
    }

    // Convert between currencies (target currency exchange rate is passed)
    double convertTo(Currency& targetCurrency) {
        double baseAmount = this->convertToBase();
        return baseAmount / targetCurrency.exchangeRate;  // Convert to target currency
    }

    // Display currency details
    void displayCurrency() {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")" << endl;
        cout << "Amount: " << amount << endl;
        cout << "Exchange Rate to Base Currency (USD): " << exchangeRate << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() override {
        return amount * exchangeRate;  // USD is the base currency, so exchangeRate is 1.0
    }

    // Overriding displayCurrency to format Dollar output
    void displayCurrency() override {
        cout << "USD Details: " << endl;
        Currency::displayCurrency();
        cout << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 0.85) {}

    // Overriding convertToBase for Euro (1 EUR = 0.85 USD, for example)
    double convertToBase() override {
        return amount * exchangeRate;  // Convert EUR to USD
    }

    // Overriding displayCurrency to format Euro output
    void displayCurrency() override {
        cout << "Euro Details: " << endl;
        Currency::displayCurrency();
        cout << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.013) {}

    // Overriding convertToBase for Rupee (1 INR = 0.013 USD, for example)
    double convertToBase() override {
        return amount * exchangeRate;  // Convert INR to USD
    }

    // Overriding displayCurrency to format Rupee output
    void displayCurrency() override {
        cout << "Indian Rupee Details: " << endl;
        Currency::displayCurrency();
        cout << endl;
    }
};
int main() {
    Dollar usdAmount(100);    // 100 USD
    Euro eurAmount(100);      // 100 EUR
    Rupee inrAmount(1000);    // 1000 INR

    // Display currency details
    usdAmount.displayCurrency();
    eurAmount.displayCurrency();
    inrAmount.displayCurrency();

    // Convert USD to EUR
    double convertedEUR = usdAmount.convertToBase() / eurAmount.convertToBase();
    cout << "Converted 100 USD to EUR: " << convertedEUR << " EUR" << endl;

    // Convert EUR to INR
    double convertedINR = eurAmount.convertToBase() / inrAmount.convertToBase();
    cout << "Converted 100 EUR to INR: " << convertedINR << " INR" << endl;

    return 0;
}

