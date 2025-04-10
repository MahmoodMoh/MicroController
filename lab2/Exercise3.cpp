#include <iostream> // The standard library
using namespace std;

int main(){ // The main function starts here

    int num1, num2; // Two integer variables are defined
    char operand; // The operands are defined through character
    

    cout <<"Give an input: " << endl; // Prompt the user to enter an integer
    cin >> num1; // Works like a scanner and it reads the input given
    cout <<"Give another input: " << endl; // Prompt for another input
    cin >> num2;// Reads the given input

    cout <<"Choose an operand (+, -, *, /): " << endl; // Prompts for an operand
    cin >> operand; // Reads or scan the operand

    switch (operand){ 
        case '+': // Addition case
        cout <<"The result is: " << num1 + num2 << endl; // Prints the result of addition
        break; //Exits the addition case

        case '-': // subtraction case
        cout <<"The result is: " << num1 - num1 << endl; // Prints the result 
        break; // Exits

        case '*':// Multiplication case
        cout <<"The result is: " << num1 * num2 << endl; //Prints out the result
        break; // Exits

        case '/': // case division
        cout <<"The result is: " << num1 / num2 << endl; //Prints the result
        break; // Exit

        default: // If all the cases fail
        cout <<" Invalid Operator! " << endl; // Print out Invalid Operator

        return 0; // The function executes successfully
        
        
    }


}


