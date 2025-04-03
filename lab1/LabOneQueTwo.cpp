#include <iostream>  //Standard library 
#include <string> // Standard string library
#include <algorithm> // Processor directive in c++ includes the algorithm header file

using namespace std;
/* This functions counts the number of vowels in a given string, takes a string as input, checks each character in the string to see if it is a vowel.
Then the functions returns the total counts ov vowels in the string*/
int countVowels(const string& str) {
    int count = 0; //Initialize a counter for the vowels
    string vowels = "AEIOUaeiou"; //define a string of vowels
    for (char c: str) {
        //If the character c is found in the vowels string, it's a vowel
        if (vowels.find(c) != string::npos) {
            count++; // increase the vowels count
        }
    }
    return count; // Return the total vowel count
}
//Main function starts in here
int main(){
    string input; // Declare a string variable to hold the user's input
    cout << "Enter a string: "; // Prompts the user to enter a string
    getline(cin, input); // Reads the full line of input

    string upperStr = input; // Converts the input string to uppercase
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), :: toupper); //Convert all the characters to uppercase
    cout << "Uppercase: " <<upperStr<< endl; //Print the Uppercase string

    //Counts the number of vowels in the input string
    int vowelCount = countVowels(input);
    cout << "Number of vowels: " << vowelCount << endl; // prints the number of vowels
     //Then reverses the input string
    string reversedStr = input; //create a copy of the input string to reverse it
    reverse(reversedStr.begin(), reversedStr.end()); // Reverses the string in places
    cout << "Reversed: " << reversedStr <<endl; // Prints the reversed string
    return 0; // End the program
}