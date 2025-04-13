#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string name;
    int id;
    float grade;
};

void addStudent(Student students[], int& count) {
    if (count >= MAX_STUDENTS) {
        cout << "Student list is full.\n";
        return;
    }

    cout << "Enter student name: ";
    cin.ignore(); // to clear input buffer
    getline(cin, students[count].name);

    cout << "Enter student ID: ";
    cin >> students[count].id;

    cout << "Enter student grade: ";
    cin >> students[count].grade;

    count++;
    cout << "Student added successfully.\n";
}

void displayStudents(const Student students[], int count) {
    if (count == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\nList of Students:\n";
    for (int i = 0; i < count; ++i) {
        cout << "Name: " << students[i].name
             << ", ID: " << students[i].id
             << ", Grade: " << students[i].grade << endl;
    }
}

void searchStudentById(const Student students[], int count) {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].id == id) {
            cout << "Student found:\n";
            cout << "Name: " << students[i].name
                 << ", ID: " << students[i].id
                 << ", Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found.\n";
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (true) {
        cout << "\nStudent Record System:\n";
        cout << "1. Add a student\n";
        cout << "2. Display all students\n";
        cout << "3. Search for a student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
