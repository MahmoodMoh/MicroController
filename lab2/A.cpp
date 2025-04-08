// EXCERSISE 1:
//A
#include <iostream>
using namespace std;

int multiply(int a, int b){
    return a*b;
}

int main(){
    int num1, num2;
    cout <<"Enter the first integer: " << endl;
    cin >> num1;
    cout <<" Enter the second integer: " << endl;
    cin >> num2;
    int result = multiply(num1, num2);

    cout << "The product is: " << result << endl;

    return 0;
     
}