#include <iostream>
using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

// All the class members are private by degfault
class Employee:AbstractEmployee {
    // attributes and members
    private:
    string Name;
    string Company;
    int Age;

    public:
    // Encapsulation
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    void setAge(int age) {
        Age = age;
    }
    int getAge() {
        return Age;
    }

    //Behavior of an employee, How can we describe the behavior of employee
    // We can describe that by a class method, using function
    void IntroduceYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
/* Constructor: Whenever an object of class is created, a constructor is invoked, which is called default
- 1. Constructor does not have return type.
2. Constructor has the same name as the class 
3. */

Employee(string name, string company, int age) {

    Name = name;
    Company = company;
    Age = age;
}

};

int main() {
    // Object or instance of the class Employee
    Employee employee1 = Employee("Saldina", "Yt-CodeBeauty", 25);

    // How to access the members of the Employee clASS
    // Object = employee1
    /*employee1.Name = "Saldina";
    employee1.Company = "YT-CodeBeauty";
    employee1.Age = 25;*/
    employee1.IntroduceYourself();

    /*employee1.Name = "Khan";
    employee1.Company = "Amazon";
    employee1.Age = 35;*/
    Employee employee2 = Employee("Khan", "Amazon", 35);
    employee2.IntroduceYourself();

    employee1.setAge(39);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old." << endl;
}

/* Encapsulation: 4 Most important pillars of Object Oriented programming
- Encapsulation: Is the idea of bandling or tieying together data, that operate on that data.
The idea of encapsulation is to private the properties of a class, and make them others use through the mothods of setters and getters

- Abstraction: Hiding complex things behind a procedure, that makes those things simple.
Ex: The idea of the smartphone's camera. The complexity behind is hidden from the user by the company,
but for the user interace it is just a button click. That process of hiding that complex side is called abstraction.*/