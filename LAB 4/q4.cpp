#include <iostream>
#include <string>
using namespace std;

class Book {
    string title, author, publisher;
    double price;
    int stock;

public:
    Book(string t, string a, string p, double pr, int s) {
        title = t;
        author = a;
        publisher = p;
        price = pr;
        stock = s;
    }

    bool isAvailable(string t, string a) {
        return (title == t && author == a);
    }

    void showBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << " copies available" << endl;
    }

    void sellBook(int copies) {
        if (copies <= stock) {
            cout << "Total Cost: $" << (copies * price) << endl;
            stock -= copies;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    }
};

int main() {
    Book book1("C++ Programming", "XYZ", "Pearson", 50.0, 10);

    string searchTitle, searchAuthor;
    int copies;

    cout << "Enter book title: ";
    getline(cin, searchTitle);
    cout << "Enter author name: ";
    getline(cin, searchAuthor);

    if (book1.isAvailable(searchTitle, searchAuthor)) {
        book1.showBookDetails();
        cout << "Enter number of copies required: ";
        cin >> copies;
        book1.sellBook(copies);
    } else {
        cout << "Book not available." << endl;
    }

    return 0;
}
