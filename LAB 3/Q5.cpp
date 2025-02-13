#include <iostream>
using namespace std;

class Book {
    string name;
    string ISBN;
    string authorName;
    string publisher;

    public:
        Book (string name , int ISBN , string authorName , string publisher){
            this->name = name;
            this->ISBN = ISBN;
            this->authorName = authorName;
            this->publisher = publisher;
        }

        string getBookName(){
        return this->name;
        }
    
        string getISBN(){
        return this->ISBN;
        }
    
        string getAuthor(){
        return this->authorName;
        }
    
        string getPublisher(){
        return this->publisher;
        }

        void getBookInfo() {
            return "Title: " + name + endl + "ISBN: " + ISBN + endl + "Author: " + authorName + endl + "Publisher: " + publisher;
        }
};

int main(int argc , char *argv[]){
    Book book[5] = {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])
    };

    for (int i=0 ; i<5 ; i++){
        cout << "BOOK INFORMATION..." << endl;
        cout << book[i].getBookInfo << endl;
    }

    return 0;
}