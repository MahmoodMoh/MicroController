#include <iostream>
#include <string>
using namespace std;


class Book{

    private:
    string title;
    int pages;
    string author = "Peter";

    protected:
    float price;

    public:
    string publisher;
    
    void setTitle(string t){
        title = t;
    
    }
    string getTitle(){
        return title;
    }

    void displayAuthorInfo(){
        cout <<"Author: " << author << endl;
    }
};

int main() {
    //A
    /*Before
    Book mybook;
    mybook.title = "Serendipity";
    cout <<mybook.title<< endl; 
    //The title cannot be compiled, because it is private.
    //In order to make it work or compile it, an object is needed to be made for it or be called via public
    //cout <<"Serendipity " << title << endl;
    
    Book mybook;
    mybook.displayTitle(); */

    //Fixed: In order to fix the issue we need to set the title public
    Book mybook;
    mybook.setTitle("Serendipity");
    cout << mybook.getTitle() << endl;

    return 0;
}