#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PolynomialHelper; // Forward declaration

class Polynomial {
    private:
        vector<int> coefficients;

        // Helper function to remove leading zeros
        void removeLeadingZeros() {
            while (!coefficients.empty() && coefficients.back() == 0) {
                coefficients.pop_back();
            }
        }

    public:
        Polynomial() {}
        Polynomial(const vector<int>& coeffs) : coefficients(coeffs) { removeLeadingZeros(); }

        friend ostream& operator<<(ostream& os, const Polynomial& p);
        friend class PolynomialHelper;

        // Overloading operator for addition
        Polynomial operator+(const Polynomial& other) const {
            vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
            for (size_t i = 0; i < coefficients.size(); i++) {
                result[i] += coefficients[i];
            }
            for (size_t i = 0; i < other.coefficients.size(); i++) {
                result[i] += other.coefficients[i];
            }
            return Polynomial(result);
        }

        // Overloading operator for subtraction
        Polynomial operator-(const Polynomial& other) const {
            vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
            for (size_t i = 0; i < coefficients.size(); i++) {
                result[i] += coefficients[i];
            }
            for (size_t i = 0; i < other.coefficients.size(); i++) {
                result[i] -= other.coefficients[i];
            }
            return Polynomial(result);
        }

        // Overloading operator for multiplication
        Polynomial operator*(const Polynomial& other) const {
            vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
            for (size_t i = 0; i < coefficients.size(); i++) {
                for (size_t j = 0; j < other.coefficients.size(); j++) {
                    result[i + j] += coefficients[i] * other.coefficients[j];
                }
            }
            return Polynomial(result);
        }
};

ostream& operator<<(ostream& os, const Polynomial& p) {
    if (p.coefficients.empty()) {
        os << "0";
        return os;
    }
    bool firstTerm = true;
    for (int i = p.coefficients.size() - 1; i >= 0; i--) {
        if (p.coefficients[i] != 0) {
            if (!firstTerm) {
                os << (p.coefficients[i] > 0 ? " + " : " - ");
            } else if (p.coefficients[i] < 0) {
                os << "-";
            }

            if (abs(p.coefficients[i]) != 1 || i == 0) {
                os << abs(p.coefficients[i]);
            }

            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
            firstTerm = false;
        }
    }
    return os;
}

class PolynomialHelper {
    public:
        // Evaluates the polynomial at a given value of x
        static int evaluate(const Polynomial& p, int xValue) {
            int result = 0;
            int power = 1;
            for (size_t i = 0; i < p.coefficients.size(); i++) {
                result += p.coefficients[i] * power;
                power *= xValue;
            }
            return result;
        }

        // Computes the derivative of the polynomial
        static Polynomial derivative(const Polynomial& p) {
            if (p.coefficients.size() <= 1) return Polynomial();
            vector<int> deriv(p.coefficients.size() - 1);
            for (size_t i = 1; i < p.coefficients.size(); i++) {
                deriv[i - 1] = p.coefficients[i] * i;
            }
            return Polynomial(deriv);
        }
};

int main() {
    Polynomial poly1({3, -2, 5}); // 5x^2 - 2x + 3
    Polynomial poly2({1, 0, -4}); // -4x^2 + 1

    cout << "Polynomial 1: " << poly1 << endl;
    cout << "Polynomial 2: " << poly2 << endl;

    Polynomial sum = poly1 + poly2;
    Polynomial diff = poly1 - poly2;
    Polynomial product = poly1 * poly2;
    Polynomial deriv = PolynomialHelper::derivative(poly1);

    cout << "Polynomial 1 + Polynomial 2: " << sum << endl;
    cout << "Polynomial 1 - Polynomial 2: " << diff << endl;
    cout << "Polynomial 1 * Polynomial 2: " << product << endl;
    cout << "Derivative of Polynomial 1: " << deriv << endl;
    cout << "Polynomial 1 evaluated at x = 2: " << PolynomialHelper::evaluate(poly1, 2) << endl;

    return 0;
}
