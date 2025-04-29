/*
Structures: User-define datatype
*/
#include <iostream>
using namespace std;

struct Smartphone{
    string name;
    int storageSpace;
    string color;
    double price;
};

struct Person {
    string name;
    int age;
    Smartphone smartphone;
};

void printSmartphoneInfo(Smartphone smartphone) {
    cout << "Name: " << smartphone.name << endl;
    cout << "StorageSpace: " << smartphone.storageSpace << endl;
    cout << "Color: " << smartphone.color << endl;
    cout << "Price: " << smartphone.price << endl;
}

void printPersonInfo(Person person) {
    cout << "name: " << person.name << endl;
    cout << "age: " << person.age << endl;
    printSmartphoneInfo(person.smartphone);
}

int main(){

    Smartphone smartphone; 
    smartphone.name = "iphone 12";
    smartphone.storageSpace = 64;
    smartphone.color = "Blue";
    smartphone.price = 1500.99;

    Smartphone smartphone2;
    smartphone2.name = "Samsung Galaxy S24 Ultra";
    smartphone2.storageSpace = 120;
    smartphone2.color = "Black";
    smartphone2.price = 1400.00;

    //printSmartphoneInfo(smartphone);
    //printSmartphoneInfo(smartphone2);

    Person p; 
    p.name = "MM";
    p.age = 28;
    p.smartphone = smartphone2;
    printPersonInfo(p);

    return 0;
    
}