#include <iostream>
using namespace std;

int main(){
    //Method 1
    /*int a = 5;
    int b = 10;

    int temp = a;
    a = b;
    b = temp;
    cout<<"a = " <<a<< "b = " << b << endl;*/

    //Method 2
    int a = 5, b = 10;
    a = a + b; // 15
    b = a - b; // 15 - 10 = 5
    a = a - b; // 15 - 5 = 10

    cout <<"a = " << a << endl;
    cout <<"b = " << b << endl;

    return 0;
}