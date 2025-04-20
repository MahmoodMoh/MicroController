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

    //B
    //The publisher is compiled, because it is public. It can be accessed from outside the class
    //It is not good to always use public, because everyone can use and modify the code.
    mybook.publisher = "Helsinki University";
    cout <<"Publisher: " << mybook.publisher << endl;

    //C
    mybook.displayAuthorInfo();  /*It works because it is declared as a public member function, 
    the same way it is done for the title in above
    If it is changed from bublic to private, then it would be private and would only be
    called from inside the class*/

    //D
    /* Access specifiers/modifiers are the options used inside the class in order to
    specify who can access the (functions, data) inside the class
    There are three main access speciefiers inside the class: Private, protected, and public.
    Private: The most restricted, can only be accessed from withen the class. Its benefit are;
    encapsulating data from outsider misusing, protects internal data of class.
    Protected: base class data that derived class should access, benefits; Enable inheritance without
    exposing members, allows child access to use base features.
    Public: Allows direct access to important functionalities.
    */

    /*E
    In c++ a class is a user-defined data type that groups related data and funtions together.
    It is like a blueprint for creating objects.
    We use classes in order to make the code organized into logical pieces, reuse them
    by creating multiple objects from them, encapsulates data and functions, like making 
    them private. 
    */

    return 0;
}