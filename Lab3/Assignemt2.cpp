#include <iostream>
#include <string>
using namespace std;
// The class name is Student
class Student {
private: //private attributes
    string name;
    int age;
    char grade;
    string group = "2025 group";  // Default value

public: // public attributes
    // Setters
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setGrade(char g) {
        grade = g;
    }

    // Getters
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    char getGrade() {
        return grade;
    }

    // Display info
    void displayInfo() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Grade: " << getGrade() << endl;
        cout << "Group: " << group << endl;
    }
};

int main() {
    Student s1;

    // Use setter methods
    s1.setName("Ali");
    s1.setAge(20);
    s1.setGrade('A');

    // Use getter methods to print individually
    cout << "Student name: " << s1.getName() << endl;
    cout << "Student age: " << s1.getAge() << endl;
    cout << "Student grade: " << s1.getGrade() << endl;

    // Call displayInfo to print everything
    s1.displayInfo();

    return 0;
}
/*A
The program compiles successfully, because all the attributes are accessed through the public functions
(setters and getters).
None of the private attributes are compilded directly from main.

B
I think setter and getter method is better, makes data controlled and cosistent.

C
The line string group = "2025 group";
is a default member initializer, means that initial value of the group attribute is already set,
even if not set manually, it already has the value.
*/