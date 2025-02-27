#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
    string title;
    string isbn;

    public:
        Book(const string& bookTitle, const string& bookIsbn)
            : title(bookTitle), isbn(bookIsbn) {}

        string getTitle() const {
            return title;
        }

        string getIsbn() const {
            return isbn;
        }
};

class Catalog {
    vector<string> isbns; 
    public:
        void addBook(const string& isbn) {
            isbns.push_back(isbn);
            cout << "Book added to catalog: ISBN " << isbn << endl;
        }

        bool findBook(const string& isbn) const {
            for (const string& bookIsbn : isbns) {
                if (bookIsbn == isbn) {
                    return true;
                }
            }
            return false;
        }
};

class Library {
    string name;
    Catalog catalog; // Composition
    vector<Book*> books; // Aggregation

    public:
        Library(const string& libraryName) : name(libraryName) {
            cout << "Library created: " << name << endl;
        }

        void addBook(Book* book) {
            books.push_back(book); 
            catalog.addBook(book->getIsbn()); 
            cout << "Book added to library: " << book->getTitle() << " (ISBN: " << book->getIsbn() << ")" << endl;
        }

        void removeBook(const string& isbn) {
            for (auto it = books.begin(); it != books.end(); ++it) {
                if ((*it)->getIsbn() == isbn) {
                    cout << "Book removed from library: " << (*it)->getTitle() << " (ISBN: " << isbn << ")" << endl;
                    books.erase(it);
                    return;
                }
            }
            cout << "Book not found in library: ISBN " << isbn << endl;
        }

        bool findBookInCatalog(const string& isbn) const {
            return catalog.findBook(isbn);
        }

        ~Library() {
            cout << "Library destroyed: " << name << endl;
        }
};

int main() {
    Book* book1 = new Book("The Great Banging", "9780743273565");
    Book* book2 = new Book("1984", "9780451524935");
    Book* book3 = new Book("To Kill her", "9780061120084");

    Library library("Central Library");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    cout << "Searching for ISBN 9780743273565: " << (library.findBookInCatalog("9780743273565") ? "Found" : "Not Found") << endl;
    cout << "Searching for ISBN 9780000000000: " << (library.findBookInCatalog("9780000000000") ? "Found" : "Not Found") << endl;

    library.removeBook("9780451524935");

    cout << "Searching for ISBN 9780451524935: " << (library.findBookInCatalog("9780451524935") ? "Found" : "Not Found") << endl;

    delete book1;
    delete book2;
    delete book3;

    cout << "End of main(). Library will be destroyed." << endl;

    return 0;
}