#include <iostream>
using namespace std;

class MenuItem {
public:
    string name;
    string type; // "food" or "drink"
    double price;

    MenuItem() {} // Default constructor

    MenuItem(string name, string type, double price) {
        this->name = name;
        this->type = type;
        this->price = price;
    }
};

class CoffeeShop {
private:
    string name;
    MenuItem menu[10]; // Fixed-size array for menu items
    string orders[10]; // Fixed-size array for orders
    int menuSize;
    int orderCount;

public:
    CoffeeShop(string shopName, MenuItem menuItems[], int size) {
        name = shopName;
        menuSize = size;
        orderCount = 0;

        for (int i = 0; i < size; i++) {
            menu[i] = menuItems[i];
        }
    }

    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (orderCount < 10) {
                    orders[orderCount++] = itemName;
                    return "Order added: " + itemName;
                } else {
                    return "Order list is full!";
                }
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders taken" << endl;
        } else {
            cout << "Orders: ";
            for (int i = 0; i < orderCount; i++) {
                cout << orders[i] << (i < orderCount - 1 ? ", " : "\n");
            }
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (orders[i] == menu[j].name) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) return "No items on the menu";

        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    void drinksOnly() {
        cout << "Drinks: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }

    void foodOnly() {
        cout << "Food: ";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                cout << menu[i].name << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    MenuItem menu[] = {
        MenuItem("Coffee", "drink", 2.50),
        MenuItem("Tea", "drink", 1.50),
        MenuItem("Sandwich", "food", 5.00),
        MenuItem("Cake", "food", 3.00)
    };

    CoffeeShop shop("Java Cafe", menu, 4);

    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Burger") << endl; // Unavailable item

    shop.listOrders();
    cout << "Total Due: $" << shop.dueAmount() << endl;

    cout << shop.fulfillOrder() << endl;
    shop.listOrders();

    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    shop.drinksOnly();
    shop.foodOnly();

    return 0;
}
