#include <iostream>
using namespace std;

int main(){
    int x = 100; // defining the original integer variable
    int& refX = x; // giving reference to the variable x

    cout <<"Original values: "<<endl; // Prints out Original values: on the screen
    cout<<"x = "<<x<< endl; // prints out the value of x
    cout<<"refX = "<<refX<<endl; // prints out the reference of x

    refX = 30; /* modifying the reference also modifies the original value of x, since they sahre the same 
    address memory*/

    //The result for both a and referenceA would become 30 after modification
    cout<<"After modifying: "<<endl;
    cout<<"x = " <<x<<endl;
    cout<<"refX = " <<refX<< endl;

    return 0;

}