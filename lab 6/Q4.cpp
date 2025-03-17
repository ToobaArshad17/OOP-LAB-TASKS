#include <iostream>
using namespace std;

class Books{
    protected:
    string genre , title , author;

    public:
       Books(string g , string t , string a) : genre(g) , title(t) , author(a) {}

       void display() {
        cout << "Book's genre:" << genre << "  |  ";
        cout << "Book's title:" << title << "  |  ";
        cout << "Book's author name:" << author << endl;
       }
};


class Fictional : public Books{
    public:
       Fictional (string t , string a) :Books("Fictional",t,a) {}
};

class Religious : public Books {
    string title , author;

    public:
       Religious (string t , string a) :Books("Religious",t,a) {}

};

int main() {
    Religious religious ("Seerat" , "Shibli Naumani");
    religious.display();

    cout << endl;

    Fictional fictional("Happy Life" , "Me");
    fictional.display();

    return 0;
}