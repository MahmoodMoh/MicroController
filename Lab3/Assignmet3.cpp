#include <iostream>
#include <string>
using namespace std;


class Car{

    private:
    string brand;
    int year;

    public:
    // Constructor
    Car(string br, int yr){
        brand = br;
        year = yr;
        cout << "Car " << brand << " from " << year << " created. " << endl;
    }
    //Destructor
    ~Car(){
        cout << "Car " << brand << ", year: " << year << endl;
    }
    void showInfo() {
        cout << "Brand: " << brand << ", year: " << year << endl;
    }
    };

int main() {
    // Pointer 'myCar' is declared on the stack
    Car* myCar = new Car("BMW", 2025); //Create object on the heap using new

    // Call showInfo method
    myCar->showInfo(); // Accessing the heap object via pointer

    // Destroy object using delete
    delete myCar;

    
    return 0;
}

/*
A
A constructor is a special funtion inside a class that is automatically called when an object is created.
It has the same name as the class. It is used to to initialize object attributes when the object is created. 

B
A destructor is alsa a special function inside a class that is automatically called, when an object
is destroyed. It has the same name as Class with a tilde(~) prefix.
Destructor is used to to free resources, close files, and perform clean-up tasks. 

C
Class Car{
public:
     Car(); // Constructor
     ~Car(); // Destructor
};
No, costructors and destructors have no return type, and not even void type. 
Because constructor initializes and destructor cleans up.

D
Stack: When object is created through stack, it is automatically managed, it is faster and safer.
New: Must use delete manually to free memory, more flexible, but risk of memory leaks. 

E
If the Constructor is not defined, the compiler automatically provides a default constructor without
any parameters. 

F
If destructor is not defined, the compiler automatically provides a default destructor, but if
Class uses dynamic memory(new), a custom destructor must be defined to avoid memory leaks
*/