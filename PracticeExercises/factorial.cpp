#include <iostream>
using namespace std;

int main(){
    // The factorial of a number

    int number;
    cout << "Number: ";
    cin >> number;
    int factorial = 1;
    for (int i = 1; i <= number; i++){
        factorial = factorial * i;
        
    }
    cout <<number << "!=" << factorial << endl;

    system("pause>0");
}