#include <iostream>
using namespace std;

bool isPrimeNumber(int number){
    bool isPrimeFlag = true;
    for (int i = 2; i < number; i++){
        if ( number % i == 0){
            return false;
        }
}
return true;
//return isPrimeFlag;
}
int main(){
    /*int number;
    cout << "Number: ";
    cin >> number;

    bool isPrimeFlag = true;
    for (int i = 2; i < number; i++){
        if ( number % i == 0){
            isPrimeFlag = false;
            break;
        }
    }*/

   /* bool isPrimeFlag = isPrimeNumber(number);
    if (isPrimeFlag)
    cout <<"Prime number " << endl;
    else
    cout << "Not Prime number" << endl;*/

    for (int i = 1; i <= 1000; i++){
        bool isPrime = isPrimeNumber(i);
        if (isPrime)
        cout << i << "is Prime number /n";
    }

    system("pause>0");
}