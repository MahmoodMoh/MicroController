// Assignment 4
#include <iostream>
using namespace std;

// 4.1 Class Vehicle includes protected attribute

class Vehicle{
    protected:
    string brand;
    int year;

    public:
    Vehicle(string b, int yr){ // constructor
        brand = b;
        year = yr;
    }
    virtual void showInfo(){ // Virtual is used to override showInfo()
        cout <<"Brand: " << brand << ", Year: " << year << endl;
    }
    virtual void startEngine(){ // override startEngine function
        cout <<"Starting engine of Vehicle " << endl;
    }
    virtual ~Vehicle() { // destructor
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
        cout <<"Brand: " << brand << endl;
        cout<<" Year: " << year << endl;
        cout <<" Number of Doors: "<< numDoors << endl;
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
            cout << "Number of doors: " << getNumDoors() << endl;
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

    cout << endl << endl;
    //2. Car object
    Car* c1 = new Car("Toyota", 2021, 4);
    c1->showInfo();
    c1->startEngine();

    cout << endl << endl;
    //3. ElectriCar using parameterized constructor
    ElectricCar* ec1 = new ElectricCar("Tesla", 2023, 4, 75);
    ec1->showInfo();
    ec1->startEngine();

    cout << endl << endl;
    //4. ElectricCar using default constructor
    ElectricCar* ec2 = new ElectricCar();
    ec2->showInfo();
    ec2->startEngine();

    cout << endl << endl;
    // Clean up memory
    delete v1;
    delete c1;
    delete ec1;
    delete ec2;

    return 0;

}
/* A
An inheritance in C++ is a way to create a new class from the base class. The derived class inherits all public
and protected members of the base class.

B
The two constructor in the ElectricCar serve different purposes and make the class more flexible. 
The default constuctor is used in order to not provide any values manually, it helps to create an ElectricCar object
without needing to input details every time. 

Parameterized Constructor:  is used when an ElectricCar object is created with custom values. The brand, year, 
number of doors and battery capacity are decided manually. 
Using both constructors is called constructor overloading. The advantage is to allow simplicity(default constructor), customization
(Parameterized constructor). It improves usability, so that objects are created based on what info is there available. 

C
If the base class constructor is not called in the initializer of the derived class:
- the default constructor of the base class is automatically called, if it exists. 
- If the base class does not have a default constructor, a compilation error occurs. 


*/