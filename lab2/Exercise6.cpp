#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100; // This defines a constant named MAX_STUDENTS

// A struct, a way to group related variables into one object.
struct Student {
    string name;
    int id;
    float grade;
};

// A function that adds a student to the students array
void addStudent(Student students[], int& count) {
    if (count >= MAX_STUDENTS) { // Check if the array is full
        cout << "Student list is full.\n"; // Printing the student list is full
        return; 
    }

    cout << "Enter student name: "; // Prompt the user to Enter the student name
    cin.ignore(); // to clear input buffer before getline
    getline(cin, students[count].name); // gets full name with spaces

    cout << "Enter student ID: "; // Prompt the user for entering the student ID
    cin >> students[count].id; 

    cout << "Enter student grade: ";
    cin >> students[count].grade;

    count++;
    cout << "Student added successfully.\n";
}
// This function displays all students currently stored, 
void displayStudents(const Student students[], int count) {
    if (count == 0) { // if no students are added yet, 
        cout << "No students to display.\n"; // Prints a message and return
        return;
    }

    cout << "\nList of Students:\n"; //Prints list of students
    for (int i = 0; i < count; ++i) { // for loop, count starts from 0 up until iteration is less than count
        cout << "Name: " << students[i].name
             << ", ID: " << students[i].id
             << ", Grade: " << students[i].grade << endl;
    }
}
// This function takes a student ID and search for that ID
void searchStudentById(const Student students[], int count) {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;

    bool found = false; // If boolean found is false
    for (int i = 0; i < count; ++i) { // for loop
        if (students[i].id == id) { // if the match is found
            cout << "Student found:\n";// prints the student found, and prints the student's info
            cout << "Name: " << students[i].name
                 << ", ID: " << students[i].id
                 << ", Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }

    if (!found) { //if not found
        cout << "Student with ID " << id << " not found.\n"; // prints Student with the input id not found
    }
}
//main function
int main() {
    Student students[MAX_STUDENTS]; //Array to store student dara
    int studentCount = 0; // how many students are added
    int choice; // user's menu choice

      // An infinite while loop, shows a menu and takes user's choice 
    while (true) {
        cout << "\nStudent Record System:\n";
        cout << "1. Add a student\n";
        cout << "2. Display all students\n";
        cout << "3. Search for a student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
              // The switch case for the choice option
        switch (choice) {
        case 1:
            addStudent(students, studentCount);
            break;
        case 2:
            displayStudents(students, studentCount);
            break;
        case 3:
            searchStudentById(students, studentCount);
            break;
        case 4:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
