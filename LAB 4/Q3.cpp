#include <iostream>
using namespace std;

class Invoice {
    string partno;
    string description;
    int quantity;
    double price;

public:
    Invoice(string partno, string description, int quantity, double price) {
        this->partno = partno;
        this->description = description;
        this->quantity = (quantity > 0) ? quantity : 0;
        this->price = (price > 0) ? price : 0.0;
    }

    double getInvoiceAmount() {
        return quantity * price;
    }
};

int main() {
    Invoice inv("1234", "bottle", 5, 10.50);
    cout << "Invoice amount is: " << inv.getInvoiceAmount() << endl;
    return 0;
}
