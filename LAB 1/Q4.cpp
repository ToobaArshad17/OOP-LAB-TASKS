#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    double weightinkg , weightinpounds;

    cout << "Enter weight in kilograms: ";
    cin >> weightinkg;
    
    weightinpounds = weightinkg * 2.2;

    cout << fixed << setprecision(2);
    cout << "Weight in kilograms: " << weightinkg << endl;
    cout << "Equivalent weight in pounds: " << weightinpounds << endl;

    return 0;
}
