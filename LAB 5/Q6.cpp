#include <iostream>
#include <vector>
using namespace std;

class CoffeeShop {
    private:
        const string Name; 
        vector<string> MenuNames; 
        vector<string> MenuTypes; 
        vector<double> MenuPrices;
        vector<string> Orders; 

    public:
        CoffeeShop(const string& name, const vector<string>& names, const vector<string>& types, const vector<double>& prices)
            : Name(name), MenuNames(names), MenuTypes(types), MenuPrices(prices) {}

        string addOrder(const string& itemName) {
            bool found = false;
            for (size_t i = 0; i < MenuNames.size(); ++i) {
                if (MenuNames[i] == itemName) {
                    found = true;
                    break;
                }
            }

            if (found) {
                Orders.push_back(itemName); 
                return itemName + " added to orders!";
            } else {
                return "This item is currently unavailable!";
            }
        }

        string fulfillOrder() {
            if (!Orders.empty()) {
                string item = Orders[0]; 
                Orders.erase(Orders.begin()); 
                return "The " + item + " is ready!";
            } else {
                return "All orders have been fulfilled!";
            }
        }

        vector<string> listOrders() const {
            return Orders;
        }

        double dueAmount() const {
            double total = 0.0;
            for (const string& order : Orders) {
                for (size_t i = 0; i < MenuNames.size(); ++i) {
                    if (MenuNames[i] == order) {
                        total += MenuPrices[i];
                        break;
                    }
                }
            }
            return total;
        }

        string cheapestItem() const {
            if (MenuNames.empty()) {
                return "No items available!";
            }
            size_t cheapestIndex = 0;
            for (size_t i = 1; i < MenuPrices.size(); ++i) {
                if (MenuPrices[i] < MenuPrices[cheapestIndex]) {
                    cheapestIndex = i;
                }
            }
            return MenuNames[cheapestIndex];
        }

        vector<string> drinksOnly() const {
            vector<string> drinks;
            for (size_t i = 0; i < MenuNames.size(); ++i) {
                if (MenuTypes[i] == "drink") {
                    drinks.push_back(MenuNames[i]);
                }
            }
            return drinks;
        }

        vector<string> foodOnly() const {
            vector<string> food;
            for (size_t i = 0; i < MenuNames.size(); ++i) {
                if (MenuTypes[i] == "food") {
                    food.push_back(MenuNames[i]);
                }
            }
            return food;
        }
};

int main() {
    vector<string> menuNames = {"Latte", "Cappuccino", "Sandwich", "Croissant", "Espresso"};
    vector<string> menuTypes = {"drink", "drink", "food", "food", "drink"};
    vector<double> menuPrices = {4.5, 5.0, 7.0, 3.5, 3.0};

    CoffeeShop shop("Java Junction", menuNames, menuTypes, menuPrices);

    cout << shop.addOrder("Latte") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Tea") << endl; 

    cout << "Orders: ";
    for (const string& order : shop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due amount: $" << shop.dueAmount() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks: ";
    for (const string& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food: ";
    for (const string& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl; 

    return 0;
}