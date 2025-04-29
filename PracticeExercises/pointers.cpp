/*
Pointers: is a variable as well , that stores address.
*/
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    cout << &n << endl; // Prints the address of n
    int* ptr = &n;
    cout << ptr << endl; // Prints the address of n
    cout << *ptr << endl; // Prints the value of n
    *ptr = 10; // Changes the value of n from 5 to 10
    cout << n << endl; // Prints out 10


    return 0;

}