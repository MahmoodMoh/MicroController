// Assignment 4
#include <iostream>
using namespace std;

// 4.1

class Vehicle{
    protected:
    string brand;
    int year;

    public:
    Vehicle(string b, int yr){
        brand = b;
        year = yr;
    }
    virtual void showInfo(){ // Virtual is used to override showInfo()
        cout <<"Brand: " << brand << ", Year: " << year << endl;
    }
    virtual void startEngine(){
        cout <<"Starting engine of Vehicle " << endl;
    }
    virtual ~Vehicle() {
        cout << "Vehicle " << brand << " destroyed. " << endl;
    }

};

// 4.2   Derived class Car

class Car : public Vehicle{
    private:
    int numDoors;

    protected:
    int getNumDoors() const { return numDoors; }

    public: 
    Car(string b, int yr, int d) : Vehicle(b, yr){
        numDoors = d;
        
    }
    // Override showInfo()
    void showInfo() override{
        cout <<"Brand: " << brand << ", Year: " << year << ", Number of Doors: "<< numDoors << endl;
        }

        // Overeide startEngine()
        void startEngine() override {
            cout <<"Car engine is starting! " << endl;
        }
        ~Car() {
            cout << "Car " << brand << " destroyed. " << endl;
        }
    };

    // 4.3 Derived class: ElectricCar

    class ElectricCar : public Car{
        private:
        int batteryCapacity;

        public: //default constructor
        ElectricCar() : Car("Nissan", 2022, 4) {
            batteryCapacity = 40;

        }

        // Parameter constructor
        ElectricCar(string b, int y, int d, int bc) : Car(b, y, d) {
            batteryCapacity = bc;
        }
        void showInfo() override {
            cout << "Brand: " << brand <<endl;
            cout << "Year: " << year << endl;
            cout << "Number of doors: " << getNumDoors << endl;
            cout << "Battery Capacity: " << batteryCapacity << "kWh" << endl;

        }
        void startEngine() {
            cout << "Electric engine is starting... dilrny buy powerful! " << endl;
        }
        ~ElectricCar() {
            cout << "ElectricCar " << brand << " destroyed. " << endl;
        }

    };


int main(){
    // 1. Vehicle object
    Vehicle* v1 = new Vehicle("Generic ", 2015);
    v1->showInfo();
    v1->startEngine();

    //2. Car object
    Car* c1 = new Car("Toyota", 2021, 4);
    c1->showInfo();
    c1->startEngine();

    //3. ElectriCar using parameterized constructor
    ElectricCar* ec1 = new ElectricCar("Tesla", 2023, 4, 75);
    ec1->showInfo();
    ec1->startEngine();

    //4. ElectricCar using default constructor
    ElectricCar* ec2 = new ElectricCar();
    ec2->showInfo();
    ec2->startEngine();

    // Clean up memory
    delete v1;
    delete c1;
    delete ec1;
    delete ec2;

    return 0;

}