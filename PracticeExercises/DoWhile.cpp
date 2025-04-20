#include <iostream>
using namespace std;

int main(){

    int usersPin = 1234, pin, errorCounter = 0;
    
    do{
        cout <<"Enter the PIN: ";
        cin >> pin;
        if (pin != usersPin)
        errorCounter ++;

    }while (errorCounter < 3 && pin!=usersPin);

    if (errorCounter < 3)
    cout <<"Loading! ";
    else
    cout <<"Several attempts, try again later! ";

    return 0;

}

/* Do while loop
for unclocking phones by attempting the pins
*/