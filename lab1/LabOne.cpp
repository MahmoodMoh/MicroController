#include <iostream> //This is the Standard Library for C++
#include <string> // Tells the compiler to include th estring library before compiling the program
using namespace std; // is a directive that tells the compiler to use the standard C++ library (namespace std)
//This defines a namespace called MagthOperations, which contains functions related to mathematical operations.
namespace MathOperations {
    int add(int a, int b){
        return a + b;
    }
}
//This one defines the TextOperations namespace
namespace TextOperations {
    //The following concatinates two strings str1, and str2
    string concat(std::string str1, std::string str2){
        return str1 + str2; // Return the concatenation of str1 and str2
    }
}
// The main function starts here
int main(){
    int sum = MathOperations::add(10, 20); // Here declares two integers for addition, using MathOperations namespace
    cout<<"Sum: " << sum << endl;

    string combinedText = TextOperations::concat("Hello, ", "World!"); // This function combines or concatinate two strings using TextOperations
    cout <<"Concateranted String: " << combinedText << endl; // Prints out the combined string
    return 0; // Ends the program
}