#include <iostream>
using namespace std;

int main() {
    
    //Two pointers pointing to the same memory(shallow copy)
    int x = 100; //defining the integer
    int* p1 = &x; // p1 points to the address of x, OR p1 holds the address of x
    int* p2 = p1; // p2 points to the address of p1, OR p2 holds the address of p1

    cout<<"The value of x is: " <<x<< endl; // prints the value of x
    cout<<"The address of x is: " <<p1<<endl; // The memory address of x
    cout <<"The address of p1 is: " <<p2<< endl; // the memory address of x
    cout <<"x is pointed by: "<<*p1 << endl; // p1 holds the memory address of x
    cout <<"x is pointed by: "<< *p2 << endl; // p2 holds p1, and p1 holds the memory address of x

    return 0;

}