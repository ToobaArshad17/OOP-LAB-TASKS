#include <iostream>
#include <string>

using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    // Constructor to initialize basic details
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut() {
        cout << title << " has been checked out." << endl;
    }

    void returnItem() {
        cout << title << " has been returned." << endl;
    }
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub,
         string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;  // Duration in minutes
    int rating;    // Rating out of 10

public:
    DVD(string t, string pubDate, string id, string pub,
        string dir, int dur, int rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pubDate, string id, string pub,
       string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
private:
    string issueNumber;

public:
    Magazine(string t, string pubDate, string id, string pub, string issue)
        : Media(t, pubDate, id, pub), issueNumber(issue) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

int main() {
    Book myBook("C++ Programming", "2023-04-01", "B001", "Tech Publishers", "John Doe", "123-456-789", 300);
    DVD myDVD("Inception", "2010-07-16", "D001", "Warner Bros.", "Christopher Nolan", 148, 9);
    CD myCD("Thriller", "1982-11-30", "C001", "Epic Records", "Michael Jackson", 9, "Pop");

    myBook.displayInfo();
    myDVD.displayInfo();
    myCD.displayInfo();

    myBook.checkOut();
    myDVD.returnItem();

    return 0;
}
