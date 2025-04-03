#include <iostream> //Main standard library
#define MAX_MIN 50 //defining the macro named MAX_MIN with a value of 50
using namespace std;

int main() //Main function starts here
{
    /*The for loop starts here, unsigned short is a data type used for storing small non negative numbers
    -The loop starts with initial i = 2, and the loop i continuous up to > 50, counts even numbers
    */
    for (unsigned short i = 2; i <= MAX_MIN; i += 2) {
        cout << i << " "; // prints the current value of i

    }
    cout << endl; //After the loop ends, prints a new line
    return 0; //program has run successfully
}