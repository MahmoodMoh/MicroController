#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    double price;

public:
    // Constructor with parameters
    Car(string m, int y, double p) : model(m), year(y), price(p) {
        cout << "Car Constructor: " << model << " (" << year << ") - $" << price << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car Destructor: " << model << " destroyed" << endl;
    }

    // Display function
    void display() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price << endl;
    }
};

class CarCollection {
private:
    Car* cars;     // Raw memory for car objects
    int count;

public:
    // Constructor
    CarCollection() {
        cout << "How many cars do you want to enter? ";
        cin >> count;
        cin.ignore(); // Clear the newline character

        // Allocate raw memory (uninitialized)
        cars = static_cast<Car*>(operator new[](count * sizeof(Car)));

        for (int i = 0; i < count; i++) {
            string model;
            int year;
            double price;

            cout << "\nEnter model for car " << i + 1 << ": ";
            getline(cin, model);

            cout << "Enter year: ";
            cin >> year;

            cout << "Enter price: ";
            cin >> price;
            cin.ignore(); // Clear the newline character

            // Use placement new to construct Car object in raw memory
            new (&cars[i]) Car(model, year, price);
        }

        cout << "CarCollection initialized with " << count << " cars" << endl;
    }

    // Destructor
    ~CarCollection() {
        for (int i = 0; i < count; i++) {
            cars[i].~Car(); // Manually call destructor
        }
        operator delete[](cars); // Free raw memory
        cout << "CarCollection destroyed" << endl;
    }

    // Display all cars
    void displayCars() const {
        cout << "\n--- Car Collection ---" << endl;
        for (int i = 0; i < count; i++) {
            cars[i].display();
        }
    }
};

int main() {
    CarCollection collection;
    collection.displayCars();
    return 0;
}
