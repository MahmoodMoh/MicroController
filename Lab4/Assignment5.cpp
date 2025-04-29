#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Car {
protected:
    string model;
    int year;
    int price;

public:
    Car(const string& m, int y, int p) : model(m), year(y), price(p) {}
    virtual ~Car() {}
    virtual void displayInfo() const {
        cout << "Model: " << model << ", Year: " << year << ", Price: $" << price;
    }
};

class ElectricCar : public Car {
    int batterySize;

public:
    ElectricCar(const string& m, int y, int p, int b) : Car(m, y, p), batterySize(b) {}
    ~ElectricCar() override {
        cout << "Destroying Electric Car: " << model << endl;
    }
    void displayInfo() const override {
        Car::displayInfo();
        cout << ", Battery: " << batterySize << " kWh" << endl;
    }
};

class GasolineCar : public Car {
    int fuelCapacity;

public:
    GasolineCar(const string& m, int y, int p, int f) : Car(m, y, p), fuelCapacity(f) {}
    ~GasolineCar() override {
        cout << "Destroying Gasoline Car: " << model << endl;
    }
    void displayInfo() const override {
        Car::displayInfo();
        cout << ", Fuel: " << fuelCapacity << " L" << endl;
    }
};

class HybridCar : public Car {
    int batterySize;
    int fuelCapacity;

public:
    HybridCar(const string& m, int y, int p, int b, int f) : Car(m, y, p), batterySize(b), fuelCapacity(f) {}
    ~HybridCar() override {
        cout << "Destroying Hybrid Car: " << model << endl;
    }
    void displayInfo() const override {
        Car::displayInfo();
        cout << ", Battery: " << batterySize << " kWh, Fuel: " << fuelCapacity << " L" << endl;
    }
};

int main() {
    vector<Car*> fleet;
    int numCars;

    cout << "Enter total number of cars: ";
    cin >> numCars;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    for (int i = 0; i < numCars; ++i) {
        cout << "\nCar " << i + 1 << " type:\n[1] Electric\n[2] Gasoline\n[3] Hybrid\nEnter choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Ignore the newline left by cin

        string model;
        int year, price;

        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: ";
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
                continue;
        }
        fleet.push_back(newCar);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining input
    }

    cout << "\n--- Fleet Information ---" << endl;
    for (const auto& car : fleet) {
        car->displayInfo();
    }

    cout << "\n--- Cleaning up fleet ---" << endl;
    for (const auto& car : fleet) {
        delete car;
    }
    fleet.clear();

    return 0;
}