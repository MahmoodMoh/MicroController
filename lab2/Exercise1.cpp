#include <iostream>
#include <cmath>

// A. Multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// B. Multiply two doubles
double multiply(double a, double b) {
    return a * b;
}

// C. Multiply with flag for rounding
double multiply(int a, double b, bool flag) {
    double result = a * b;
    if (flag) {
        result = std::round(result);    // rounds to nearest
    }
    return result;
}

int main() {
    // Test case A: multiply two integers
    int intResult = multiply(5, 3);
    std::cout << "Integer multiplication (5 * 3): " << intResult << std::endl;
    
    // Test case B: multiply two doubles
    double doubleResult = multiply(2.5, 4.2);
    std::cout << "Double multiplication (2.5 * 4.2): " << doubleResult << std::endl;
    
    // Test case C1: multiply int and double with flag false
    double mixedResult1 = multiply(3, 2.7, false);
    std::cout << "Mixed multiplication no rounding (3 * 2.7): " << mixedResult1 << std::endl;
    
    // Test case C2: multiply int and double with flag true
    double mixedResult2 = multiply(3, 2.7, true);
    std::cout << "Mixed multiplication with rounding (3 * 2.7): " << mixedResult2 << std::endl;
    
    return 0;
}