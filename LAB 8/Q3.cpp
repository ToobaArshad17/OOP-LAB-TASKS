#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LargeIntegerHelper; // Forward declaration

class LargeInteger {
private:
    vector<int> digits; // least significant digit first
    bool isNegative;

    // Function to remove unnecessary leading zeros
    void stripLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    LargeInteger() : isNegative(false) { digits.push_back(0); }
    LargeInteger(string num) {
        isNegative = (num[0] == '-');
        for (int i = num.length() - 1; i >= (isNegative ? 1 : 0); --i) {
            digits.push_back(num[i] - '0');
        }
        stripLeadingZeros();
    }

    // Addition operation for large integers
    LargeInteger operator+(const LargeInteger& other) const {
        if (isNegative == other.isNegative) {
            LargeInteger result;
            result.isNegative = isNegative;

            result.digits.clear();
            int carry = 0, sum;
            
            int maxSize = max(digits.size(), other.digits.size());
            
            for (int i = 0; i < maxSize || carry; ++i) {
                int d1 = (i < digits.size()) ? digits[i] : 0;
                int d2 = (i < other.digits.size()) ? other.digits[i] : 0;
                
                sum = d1 + d2 + carry;
                carry = sum / 10;
                result.digits.push_back(sum % 10);
            }
            result.stripLeadingZeros();
            return result;
        }
        return *this - (-other);
    }
    
    // Negation of the large integer
    LargeInteger operator-() const {
        LargeInteger result = *this;
        if (!(digits.size() == 1 && digits[0] == 0)) {
            result.isNegative = !isNegative;
        }
        return result;
    }

    // Subtraction operation for large integers
    LargeInteger operator-(const LargeInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }
        
        bool negResult = *this < other;
        const LargeInteger& larger = negResult ? other : *this;
        const LargeInteger& smaller = negResult ? *this : other;

        LargeInteger result;
        result.isNegative = negResult;
        result.digits.clear();

        int borrow = 0, diff;

        for (int i = 0; i < larger.digits.size(); ++i) {
            int d1 = larger.digits[i];
            int d2 = (i < smaller.digits.size()) ? smaller.digits[i] : 0;

            diff = d1 - d2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.digits.push_back(diff);
        }
        result.stripLeadingZeros();
        return result;
    }
    
    // Comparison operations
    bool operator<(const LargeInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (digits.size() != other.digits.size()) {
            return isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator==(const LargeInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const LargeInteger& other) const { 
        return !(*this == other); 
    }

    bool operator>(const LargeInteger& other) const { 
        return other < *this; 
    }

    bool operator<=(const LargeInteger& other) const { 
        return !(other < *this); 
    }

    bool operator>=(const LargeInteger& other) const { 
        return !(*this < other); 
    }

    // Overloading output stream for printing
    friend ostream& operator<<(ostream& out, const LargeInteger& num) {
        if (num.isNegative) out << '-';
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            out << num.digits[i];
        }
        return out;
    }

    // Overloading input stream for reading input
    friend istream& operator>>(istream& in, LargeInteger& num) {
        string input;
        in >> input;
        num = LargeInteger(input);
        return in;
    }
};

int main() {
    LargeInteger num1, num2;
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;

    cout << "Sum: " << (num1 + num2) << endl;
    cout << "Difference: " << (num1 - num2) << endl;
    cout << "Comparison: " << (num1 > num2 ? "First number is greater" : "Second number is greater or equal") << endl;
    return 0;
}
