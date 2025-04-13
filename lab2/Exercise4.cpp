#include <iostream>
using namespace std;

int main() {  // Added braces for main()
    int num;

    while (true) {  // Added braces for while loop
        cout << "Enter a number: ";
        cin >> num;

        if (num < 0) {
            cout << "Negative number entered. Exiting..." << endl;
            break;  // Exit loop if negative
        }

        if (num == 0) {
            cout << "Zero entered. Skipping..." << endl;
            continue;  // Skip to next iteration
        }

        // Only reaches here if num is positive
        cout << "The square of " << num << " is " << num * num << endl;
    }

    return 0;
}