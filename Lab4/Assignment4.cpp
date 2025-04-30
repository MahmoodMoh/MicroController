#include <iostream>
#include <string>
using namespace std;

/*
 -Demonstrates input behavior WITHOUT using cin.ignore()
 -Shows how getline() can be skipped due to leftover newline character
 */
void withoutIgnore() {
    cout << "\n=== Without cin.ignore() ===\n";
    int age;
    string name;

    // Prompt for age (uses cin >> which leaves '\n' in buffer)
    cout << "Enter your age: ";
    cin >> age;

    // Prompt for name (uses getline which reads until newline)
    // Will immediately consume the leftover '\n' from previous input
    cout << "Enter your full name: ";
    getline(cin, name); // Problem: Skips input because of leftover '\n'

    // Output shows name is empty
    cout << "Age: " << age << ", Name: " << name << endl;
}

/*
 * Demonstrates proper input behavior WITH cin.ignore()
 * Shows how to correctly handle mixed input types
 */
void withIgnore() {
    cout << "\n=== With cin.ignore() ===\n";
    int age;
    string name;

    // Prompt for age (same as before)
    cout << "Enter your age: ";
    cin >> age;

    // Clear the input buffer by discarding leftover newline
    cin.ignore(); // Solution: Removes the '\n' from buffer

    // Now getline will wait for actual user input
    cout << "Enter your full name: ";
    getline(cin, name); // Works correctly now

    // Output shows both values properly
    cout << "Age: " << age << ", Name: " << name << endl;
}

/*
 * Main function that demonstrates both scenarios
 */
int main() {
    // First show the problematic case
    withoutIgnore();

    // Then show the corrected version
    withIgnore();

    return 0;
}