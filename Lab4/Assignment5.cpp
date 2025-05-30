// List of libraries...
#include <iostream>     // For input/output operations (cout, cin)
#include <vector>       // To use std::vector container
#include <string>       // To use text (string)
#include <limits>       // To clear input buffer (ignore bad input)

using namespace std;

class Car {
    // Protected is the child class, means the derived classes can also access these variables
    protected:
    string model;
    int year;
    int price;

    public:
    // Constructor initializes the car with model, year, and price
    Car(const string& m, int y, int p) : model(m), year(y), price(p) {}

        // Virtual destructor for proper cleanup in derived classes
        virtual ~Car(){}

        // Virtual method lets child classes override (change) this behavior. Constant does not let any change in the object
        virtual void displayInfo() const {
            cout << "Model: " << model << ", year: " << year << ", Price: $" << price;

        }
    };

    // Derived Class: ElectricCar

    class ElectricCar: public Car {
        int batterySize;     // Battery size in kWh

        public:
        // Constructor initializes base and derived class members
        ElectricCar(const string& m, int y, int p, int b) : Car(m, y, p), batterySize(b){}

        // Destructor, destroys the ElectricCar and prints a message
        ~ElectricCar() override { // Override updates or uses the functions from the parent class
            cout <<"Destroying Electric Car: " << model << endl;
        }

        //Overriding is like using the base class attributes
        void displayInfo() const override {
            Car::displayInfo();  // Go to the class named Car and use its displayInfo
            cout << ", Battery: " << batterySize << "kWh" << endl; // Prints out the batterySize info

        }
    };

    
    // Derived class: GasolineCar

    class GasolineCar : public Car {
        int fuelCapacity;  

        public:
        // Constructor 
        GasolineCar(const string& m, int y, int p, int f) : Car(m, y, p), fuelCapacity(f)  {}

        // Destructor 
        ~GasolineCar () override {
            cout <<"Destroying GasolineCar: " << model << endl;
        }

            // Overriding the displayInfo
            void displayInfo() const override {
                Car::displayInfo();
                cout << ", Fuel: " << fuelCapacity << " L " << endl;

            }
        };


        // Derived class: HybridCar
        class HybridCar : public Car {
            int batterySize;
            int fuelCapacity;

            public:
            // Constructor
            HybridCar(const string& m, int y, int p, int b, int f) : Car(m, y, p), batterySize(b), fuelCapacity(f) {}

            // Destructor
            ~HybridCar() override{
                cout << "Destroying Hybrid Car: " << model << endl;
            }

            // Overriding the displayInfo from the parent class and prints the child's attribute too
            void displayInfo() const override {
                Car::displayInfo();
                cout <<", Battery: " << batterySize << "kWh, Fuel: " << fuelCapacity << " L " << endl;
            }
        };



        // Main Function
        
        int main()  {
            vector<Car*> fleet;    //   Dynamic array of pointers to Car (polymorphism)
            int numCars;

            // Ask user for number of cars
            cout <<"Enter total number of cars: ";
            cin >> numCars;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  

            // Loop to collect data for each car
            for (int i = 0; i < numCars; i++)  {
                cout << "\nCar " << i + 1 << " type: \n[1] Electric \n[2] Gasoline\n[3] Hybrid\nEnter choice: ";
                int choice;
                cin >> choice;
                cin.ignore();  // Remove leftover newline from input

                string model;
                int year, price;

                // Collect common information
                cout << "Enter model: ";
                getline(cin, model);  // getline to allow spaces in model  name
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter price: ";
                cin >> price;

                Car* newCar = nullptr;    // Pointer to base class (will point to actual car type)

                // Depending on user choice, create the appropriate car
                switch (choice)  {
                    case 1: {
                        int battery;
                        cout << "Enter battery size (kWh): ";
                        cin >> battery;
                        newCar = new ElectricCar(model, year, price, battery);
                        break;
                    }
                    case 2:  {
                        int fuel;
                        cout << "Enter fuel capacity (L): ";
                        cin >> fuel;
                        newCar = new GasolineCar(model, year, price, fuel);
                        break;
                    }
                    case 3: {
                        int battery, fuel;
                        cout << "Enter battery size (kWh): ";
                        cin >> battery;
                        cout << "Enter fuel capacity (L): ";
                        cin >> fuel;
                        newCar = new HybridCar(model, year, price, battery, fuel);
                        break;

                    }
                    default:
                    cout << "Invalid choice!" << endl;
                    continue;    // Skip the rest of the loop and asks again
                }

                // Add car to fleet
                fleet.push_back(newCar);


                // Clear leftover input
                cin.ignore (numeric_limits<streamsize>::max(), '\n');

            }

            // Display all cars in fleet
            cout << "\n--- Fleet Information ---" << endl;
            for (const auto& car : fleet) {
                car->displayInfo();    // Polymorphic call to derived class display

            }
            // Clean up dynamic memory
            cout << "\n--- Cleaning up fleet ---" << endl;
            for (const auto& car : fleet)  {
                delete car;    // Destructor is called, including derived class ones

            }

            fleet.clear();     // Optional, clears the vector



            return 0;
        }