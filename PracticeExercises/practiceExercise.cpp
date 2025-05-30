#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;


class Car  {
    protected:
    string model;
    int year;
    int price;

    public:
    // Constructor
    Car(const string& m, int y, int p) : model(m), year(y), price(p) {}

    // Destructor 
    virtual ~Car()  {}

    // Virtual displayInfo
    virtual void displayInfo() const{
        cout <<"Model: " <<model<< ", Year: " <<year<< ", Price: " <<price<< endl;
    }
};

// Derived Classes

class ElectricCar : public Car {
    int batterySize;

    public:
    // Constructor for the derived class
    ElectricCar(const string& m, int y, int p, int b) : Car(m, y, p), batterySize(b) {}

    // Destructor
    ~ElectricCar() override{
        cout <<"Destroying Electric Car: " << model << endl;
    }

    void displayInfo() const override{
        Car::displayInfo();
        cout<<", Battery: " << batterySize << "kWh" << endl;
    }
};

// Gasoline Car
class GasolineCar : public Car {
    int fuelCapacity;

    public:
    // Constructor
    GasolineCar(const string& m, int y, int p, int f) : Car(m, y, p), fuelCapacity(f) {}

    // Destructor
    ~GasolineCar () {
        cout <<"Destroying Gasoline Car: " << model << endl;

    }
        // GetInfo
        void displayInfo() const override {
            Car::displayInfo();
            cout <<", Fuel: " << fuelCapacity << "L" << endl;
        }
    };

    // Hybrid CAr
    class HybridCar : public Car{
        int batterySize;
        int fuelCapacity;

        public:
        // Constructor
        HybridCar(const string& m, int y, int p, int b, int f): Car(m, y, p), batterySize(b), fuelCapacity(f) {}

        // Destructor
        ~HybridCar() {
            cout <<"Destroying the Hybrid Car: " << model << endl;
        }

            // Displayinfo
            void displayInfo() const override {
                Car::displayInfo();
                cout <<", Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << "L" << endl;
            }
        };


int main() {
    vector<Car*>fleet;
    int numCars;

    cout <<"Enter total number of Cars: ";
    cin >> numCars;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numCars; i++) {
        cout <<"Car " << i+1 << " type: \n[1] Electric \n[2] Gasoline \n[3] Hybrid \nEnter choice:";
        int choice;
        cin >> choice;
        cin.ignore();

        string model;
        int year, price;
        cout <<"Enter model: ";
        getline(cin, model);

        cout <<"Enter year: ";
        cin >> year;

        cout <<"Enter price: ";
        cin >> price;

        Car* newCar = nullptr;

        switch (choice) {
            case 1: {
                int battery;
                cout << "Enter battery size (kWh): ";
                cin >> battery;
                newCar = new ElectricCar(model, year, price, battery);
                break;
            }
            
            case 2: {
                int fuel;
                cout <<"Enter Fuel Capacity (L): ";
                cin >> fuel;
                newCar = new GasolineCar(model, year, price, fuel);
                break;
            }

            case 3: {
                int battery, fuel;
                cout <<"Enter battery size (kWh): ";
                cin >> battery;
                cout <<"Enter fuel Capacity (L): ";
                cin >> fuel;
                newCar = new HybridCar(model, year, price, battery, fuel);
                break;
            }
            default:
            cout <<"Invalid choice!" << endl;
            continue;
        }

        fleet.push_back(newCar);

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        }

        cout <<"\n--- Fleet Information --- ";
        for (const auto& car: fleet) {
            car->displayInfo();

        
        }

        cout <<"\n--- Cleaning up fleet ---";
        for (const auto& car: fleet) {
            delete car;

        



    }
    fleet.clear();



    return 0;
}