/*C++ Functions
Function is a block of code, that is grouped together to solve and perform a specific task.
In order to perform that function, needs to be called. 
- Beside the main function, one can make his own function. Inside the paranthesis one can write arguments or parameters.

Why functions exist? They make the code reusable 
What are arguments and parameters?
Sometimes a function needs to receive a certain value or variable, and then perform a certain task on that value or variable.

Ex:
void introduceMe(string name){
         cout <<"My name is " << name << endl;
 then in the main function the parameter should be passed as: 
         introduseMe("Mahmood");
         introduceMe("Khan");        
}
*/

/*
What is return type function? 

*/
#include <iostream>
using namespace std;

// Self made function
void function(){
    cout << "Hello from function () " << endl; /*
    It is not going to be exevutedd unless it is called or invoked from main function*/
}

void main(){

    // The self made function is called, in order to be executed
    function();
    
    /* Function can also be written as following, but it needs to be declared before the main function like: void function();

    void function(){
    cout << "Hello from function() " << endl;
    }
    */
}