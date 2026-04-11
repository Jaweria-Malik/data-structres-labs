#include <iostream>
#include <string>
using namespace std;


class Item {
public:
    virtual void display() = 0;   // pure virtual function
};

class Book : public Item {
public:
    string title;
    string author;
    int pages;

    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    void display() {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

// ---------- Newspaper Class ----------
class Newspaper : public Item {
public:
    string name;
    string date;
    string edition;

    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    void display() {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

// ---------- Template Linear Search ----------
template <class T>
int linearSearch(T arr[], int size, string key) {
    for (int i = 0; i < size; i++) {
        if (arr[i].title == key || arr[i].name == key) {
            return i;
        }
    }
    return -1;
}

// ---------- Library Class ----------
class Library {
public:

    Book books[10];
    Newspaper newspapers[10];

    int bookCount = 0;
    int newsCount = 0;

    void addBook(Book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newsCount] = n;
        newsCount++;
    }

    void displayCollection() {

        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "\nNewspapers:\n";
        for (int i = 0; i < newsCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    // ---------- Sorting ----------
    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = i + 1; j < bookCount; j++) {
                if (books[i].pages > books[j].pages) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newsCount - 1; i++) {
            for (int j = i + 1; j < newsCount; j++) {
                if (newspapers[i].edition > newspapers[j].edition) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }

    // ---------- Search ----------
    Book* searchBookByTitle(string title) {

        int index = linearSearch(books, bookCount, title);

        if (index != -1)
            return &books[index];
        else
            return NULL;
    }

    Newspaper* searchNewspaperByName(string name) {

        int index = linearSearch(newspapers, newsCount, name);

        if (index != -1)
            return &newspapers[index];
        else
            return NULL;
    }
};

// ---------- Main Function ----------
int main() {

    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found\n";
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");

    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found\n";
    }

    return 0;
}
