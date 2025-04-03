#include <iostream>  //The Library
using namespace std; 

int main(){
    int num, reversed = 0; // Creating variables for the input and output

    cout <<"Enter an integer: " ; //Prompts the user for entering an integer number
    cin >> num; //Takes input from the user
    
    //Loop runs untel the num becomes 0
    for (; num > 0; num /= 10) {
        int lastDigit = num % 10; // Get the last digit
        reversed = reversed * 10 + lastDigit; // Shift previous digits left and add new one
    }
    cout <<"Reversed number: " <<reversed<< endl; //Displays the reversed number
    return 0; // End the program
}