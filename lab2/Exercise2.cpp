#include <iostream>
using namespace std;

// Swap using pointers
void swapUsingPointers(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Swap using references
void swapUsingReferences(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

int main() {
    float x = 10.5, y = 20.0;
    float temp = x;
    x = y;
    y = temp;
    cout <<"x = " << x << endl;
    cout <<" y = " << y << endl;

    cout << "Before pointer swap: x = " << x << ", y = " << y << endl;
    swapUsingPointers(&x, &y); // pass addresses
    cout << "After pointer swap: x = " << x << ", y = " << y << endl;

    swapUsingReferences(x, y); // pass by reference
    cout << "After reference swap: x = " << x << ", y = " << y << endl;

    return 0;
}
