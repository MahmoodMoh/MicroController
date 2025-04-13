#include <iostream>
using namespace std;

int main() {  
    int num; //defining the integer variable

    while (true) {  // Infinite loop, if true
        cout << "Enter a number: "; // Prompt the user to enter a number
        cin >> num; // scanning or reading the input number entered by the user

        if (num < 0) { // if the given number is less than zero
            cout << "Negative number entered. Exiting..." << endl; // print Exiting...
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