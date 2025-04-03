#include <iostream> //Standard library in C++
#define SQUARE(x) ((x) *(x)) // Define a macro SQUARE that calculates the squate of the argument x
using namespace std;
// The main function starts in here
int main(){
    int num; // Declares an integer variable 'num' to store the user input
    cout <<" Enter an integer: "; // Prompts the user to Enter an enteger
    cin >> num; // Reads the number entered by the user and store it in 'num'
    cout << "Square of " << num << " is: " << SQUARE(num) << endl; // Prints the result

    return 0; //The program ends successfully
}