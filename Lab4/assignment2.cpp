#include <iostream>
#include <string>
using namespace std;

/*Example1:
In example 1, we use a statically allocated array of Book objects, where memory management is handled automatically. 
*/
class Book {
    private:
    string title;
    int pages;

    public:
    // Constructor
    Book(string t = "Untitled", int p = 0) : title(t), pages(p) {
        cout <<"Book Constructor:  \"" << title << "\" with " << pages << " pages\n";

    }

    // Destructor
    ~Book(){
        cout << "Destructor: \"" << title << "\" destroyed \n";
    }
    // Method to display book info
    void display() {
        cout << " Title: " << title << ", Pages: " << pages << endl;
    }

};

/* Example2: 
In example 2, memory is dynamically allocated for the books inside a BookShelf class, allowing runtime flexibility, biut requiring
manual memory cleanup using delete[].
*/
class BookShelf {
    private:
    Book* books;   // pointer to Book array
    int size;

    public:
    // Constructor: dynamically create array and initializ<e it 
    BookShelf() {
        size = 3;
        books = new Book[size] {
            Book("C++ Fundamentals", 300),
            Book("DataStructures", 450),
            Book("Algorithms", 500)

        };
        cout <<"BookShelfconstructor: Shelf initiali<ed with " << size << " books \n";
        }
        // Destructor: clean up heap memory
        ~BookShelf() {
            delete[] books;
            cout << "BookShelf Destructor: Shelf destroyed\n";
        }
        void displayBooks() const {
            cout << "\nBooks on shelf:\n";
            for (int i = 0; i < size; ++i) {
                books[i].display();
            }
        }
    
};


int main() {
    BookShelf* shelf = new BookShelf(); // created on heap
    shelf->displayBooks();


    delete shelf; // cleanup
    
    return 0;
}

/*
The destructors:
In example 1;
The destructor works even if it is deleted.
Destructors are called automaticaly by the system, when the array goes out of scope.


In Example2:
If destructor is deleted, it will still compile and run, but leads to a memory leak.
Without the destructor Example 2, memory allocated on the heap would not be freed, causing a memory leak. 
Therefore, while both examples demonstrate object-oriented principles, Example 2 shows the importance of managing dynamic memory correctly.


*/