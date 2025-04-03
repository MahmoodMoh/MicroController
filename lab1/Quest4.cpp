#include <iostream>
#define SQUARE(x) ((x) *(x))
using namespace std;

int main(){
    int num;
    cout <<" Enter an integer: ";
    cin >> num;
    cout << "Square of " << num << " is: " << SQUARE(num) << endl;

    return 0;
}