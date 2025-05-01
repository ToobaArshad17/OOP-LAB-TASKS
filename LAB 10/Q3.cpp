#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <cstdlib> // For rand()
using namespace std;

string generateUUID() {
    return to_string(rand() % 1000000);
}

struct User {
    string user_id;
    string first_name;
    string last_name;
    string address;
    string email;
};

struct Product {
    string product_id;
    string product_name;
    string description;
    int price;
};

struct Order {
    string order_id;
    string user_id;
    string product_id;
    int total_paid;
};

const string USERS_FILE = "users.txt";
const string PRODUCTS_FILE = "products.txt";
const string ORDERS_FILE = "orders.txt";

void createDummyData();
vector<User> readUsers();
vector<Product> readProducts();
vector<Order> readOrders();
vector<string> getProductsForUser(const string& firstName);

int main() {
    srand(time(0));

    createDummyData();
    
    cout << "Products ordered by Linus:" << endl;
    vector<string> products = getProductsForUser("Linus");
    for (const auto& product : products) {
        cout << "- " << product << endl;
    }
    
    return 0;
}

void createDummyData() {
    vector<User> users = {
        {generateUUID(), "Linus", "Torvalds", "123 Linux St", "linus@linux.com"},
        {generateUUID(), "Bill", "Gates", "456 Microsoft Ave", "bill@microsoft.com"},
        {generateUUID(), "Steve", "Jobs", "789 Apple Blvd", "steve@apple.com"}
    };
    
    vector<Product> products = {
        {generateUUID(), "Linux OS", "Open source system", 0},
        {generateUUID(), "Windows", "Proprietary operating system", 199},
        {generateUUID(), "MacOS", "Apple operating system", 299},
        {generateUUID(), "Editor", "Basic text editing software", 49}
    };
    
    vector<Order> orders = {
        {generateUUID(), users[0].user_id, products[0].product_id, 0},
        {generateUUID(), users[0].user_id, products[3].product_id, 49},
        {generateUUID(), users[1].user_id, products[1].product_id, 199},
        {generateUUID(), users[2].user_id, products[2].product_id, 299}
    };
    
    ofstream userFile(USERS_FILE);
    for (const auto& user : users) {
        userFile << user.user_id << "," << user.first_name << "," 
                 << user.last_name << "," << user.address << "," 
                 << user.email << "\n";
    }
    userFile.close();

    ofstream productFile(PRODUCTS_FILE);
    for (const auto& product : products) {
        productFile << product.product_id << "," << product.product_name << "," 
                    << product.description << "," << product.price << "\n";
    }
    productFile.close();
    
    ofstream orderFile(ORDERS_FILE);
    for (const auto& order : orders) {
        orderFile << order.order_id << "," << order.user_id << "," 
                  << order.product_id << "," << order.total_paid << "\n";
    }
    orderFile.close();
}

vector<User> readUsers() {
    vector<User> users;
    ifstream userFile(USERS_FILE);
    string line;
    
    while (getline(userFile, line)) {
        stringstream ss(line);
        User user;
        getline(ss, user.user_id, ',');
        getline(ss, user.first_name, ',');
        getline(ss, user.last_name, ',');
        getline(ss, user.address, ',');
        getline(ss, user.email, ',');
        users.push_back(user);
    }
    
    userFile.close();
    return users;
}

vector<Product> readProducts() {
    vector<Product> products;
    ifstream productFile(PRODUCTS_FILE);
    string line;
    
    while (getline(productFile, line)) {
        stringstream ss(line);
        Product product;
        getline(ss, product.product_id, ',');
        getline(ss, product.product_name, ',');
        getline(ss, product.description, ',');
        string priceStr;
        getline(ss, priceStr, ',');
        product.price = stoi(priceStr);
        products.push_back(product);
    }
    
    productFile.close();
    return products;
}

vector<Order> readOrders() {
    vector<Order> orders;
    ifstream orderFile(ORDERS_FILE);
    string line;
    
    while (getline(orderFile, line)) {
        stringstream ss(line);
        Order order;
        getline(ss, order.order_id, ',');
        getline(ss, order.user_id, ',');
        getline(ss, order.product_id, ',');
        string totalStr;
        getline(ss, totalStr, ',');
        order.total_paid = stoi(totalStr);
        orders.push_back(order);
    }
    
    orderFile.close();
    return orders;
}

vector<string> getProductsForUser(const string& firstName) {
    vector<User> users = readUsers();
    vector<Order> orders = readOrders();
    vector<Product> products = readProducts();
    
    vector<string> result;
    
    string userId;
    for (const auto& user : users) {
        if (user.first_name == firstName) {
            userId = user.user_id;
            break;
        }
    }
    
    if (userId.empty()) return result;

    vector<string> productIds;
    for (const auto& order : orders) {
        if (order.user_id == userId) {
            productIds.push_back(order.product_id);
        }
    }
    
    for (const auto& product : products) {
        for (const auto& pid : productIds) {
            if (product.product_id == pid) {
                result.push_back(product.product_name);
                break;
            }
        }
    }
    
    return result;
}