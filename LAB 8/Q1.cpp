#include<iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;
    
    // Helper function to find the greatest common divisor (GCD)
    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Reduces the fraction to its simplest form
    void simplifyFraction() {
        int gcd = calculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Ensure the denominator is positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor initializes the fraction and simplifies it
    Fraction(int num = 0, int den = 1) {
        numerator = num;
        denominator = den;
        simplifyFraction();
    }

    // Overloaded operator for addition of fractions
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    // Overloaded operator for subtraction of fractions
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    // Overloaded operator for multiplication of fractions
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Overloaded operator for division of fractions
    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Overloaded operator for equality check
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    // Overloaded operator for inequality check
    bool operator!=(const Fraction& other) const {
        return numerator != other.numerator || denominator != other.denominator;
    }

    // Overloaded operator for less-than comparison
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Overloaded operator for greater-than comparison
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    // Overloaded operator for less-than-or-equal comparison
    bool operator<=(const Fraction& other) const {
        return numerator * other.denominator <= other.numerator * denominator;
    }

    // Overloaded operator for greater-than-or-equal comparison
    bool operator>=(const Fraction& other) const {
        return numerator * other.denominator >= other.numerator * denominator;
    }

    // Overloaded output stream operator to display the fraction
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator;
        if (f.denominator != 1) {
            os << "/" << f.denominator;
        }
        return os;
    }

    // Overloaded input stream operator to read a fraction
    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.simplifyFraction();
        return is;
    }
};

int main() {
    Fraction fraction1, fraction2;

    // Input two fractions from the user
    cout << "Enter two fractions (a/b): ";
    cin >> fraction1 >> fraction2;

    // Display simplified fractions
    cout << "\nSimplified Fraction 1: " << fraction1 << endl;
    cout << "Simplified Fraction 2: " << fraction2 << endl;
    
    // Perform and display arithmetic operations
    cout << "\nArithmetic Operations : " << endl << endl;
    cout << fraction1 << " + " << fraction2 << " = " << (fraction1 + fraction2) << endl;
    cout << fraction1 << " - " << fraction2 << " = " << (fraction1 - fraction2) << endl;
    cout << fraction1 << " * " << fraction2 << " = " << (fraction1 * fraction2) << endl;
    cout << fraction1 << " / " << fraction2 << " = " << (fraction1 / fraction2) << endl;
    
    // Perform and display relational comparisons
    cout << "\nRelational Operators : " << endl << endl;
    cout << fraction1 << " == " << fraction2 << " ? " << (fraction1 == fraction2 ? "True" : "False") << endl;
    cout << fraction1 << " != " << fraction2 << " ? " << (fraction1 != fraction2 ? "True" : "False") << endl;
    cout << fraction1 << " < " << fraction2 << " ? " << (fraction1 < fraction2 ? "True" : "False") << endl;
    cout << fraction1 << " > " << fraction2 << " ? " << (fraction1 > fraction2 ? "True" : "False") << endl;
    cout << fraction1 << " <= " << fraction2 << " ? " << (fraction1 <= fraction2 ? "True" : "False") << endl;
    cout << fraction1 << " >= " << fraction2 << " ? " << (fraction1 >= fraction2 ? "True" : "False") << endl;

    return 0;
}
