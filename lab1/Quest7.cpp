#include <iostream>
#include <string>
#include <cctype> // This is the library for chraracter checking function

#define MIN_LENGTH 8 //Defining macro for minimum password

using namespace std;

int main(){
    string password; //Creating a string variable for the password
    bool caseUpper = false, caseLower = false, caseDigit = false, caseSpecial = false; // In here we define the passwords requirements


    cout <<"Enter your password: ";
    cin >> password; //Take password input from the user
    
    if(password.length() < MIN_LENGTH) {
        cout <<"Weak password: must be at least " << MIN_LENGTH << " characters long." << endl;
        // Here we check if the password length is less than the minimum required length
        return 0; // Exits the program early, if the length is less than minimum
    }
    //In here the for loop loops through each character in the password to check for characger types
    for  (char ch : password) {
        if (isupper(ch)) caseUpper = true; // Checks if the character is uppercase, sets containsUpper to true
        else if(islower(ch)) caseLower = true; // Checks if the character is lowercase, sets caseLower to true
        else if (isdigit(ch)) caseDigit = true; // Checks if the character is a digit, sets caseDigit to true
        else if (ispunct(ch)) caseSpecial = true; // Checks if the character is a special character,sets caseSpecial to true
    }
    //After the for loop, the following checks if all the conditions are satisfied for a strong password
    if (caseUpper && caseLower && caseDigit && caseSpecial){
        cout << "Strong Password" <<endl; // If all conditions are met, then print Strong password
        }else {
            cout <<"Weak Password: Missing"; // If some conditions are not met, print which condition is missing
            if (!caseUpper) cout <<"uppercase letter, "; //If no uppercase letter is found, print this
            if (!caseLower) cout <<"lowercase letter, ";  //If no lower case letter, print this
            if (!caseDigit) cout <<"digit, "; // If no digit number, print this
            if (!caseSpecial) cout<<"special character, "; //If no Special character, print this
            cout << endl;

            return 0;
        }

}