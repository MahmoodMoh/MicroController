#include <iostream> //include inpu-output library
using namespace std;

int main(){
    int num, sum = 0; //declare variables for the inputs
    cout <<"Enter an integer: "; //Prompts the user for giving an integer
    cin>>num; //This one takes command input
    num = abs(num); //This command makes the negative numbers positive

    for (; num > 0; num/= 10) //the loop runs until the num becomes 0 
    {
        sum += num % 10; //extract the last digit using % and add it to the sum.
        
    }//Removes the last digit using /= 10 and shift numbers to the right
    cout <<" Sum of digits = " <<sum<< endl; //displays the result

    return 0;

}