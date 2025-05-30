#include <iostream>
#include <string>
using namespace std;

// Define a class to represent complex numbers
class Complex {
private:
    double real;  // Real part of the complex number
    double imag;  // Imaginary part of the complex number

public:
    // Constructor with default values
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload operator for printing complex numbers
    // Note: it must be a friend function to access private members
    friend ostream& operator<<(ostream& COUT, const Complex& c) {
        if (c.imag >= 0)
            COUT << c.real << " + " << c.imag << "i";
        else
            COUT << c.real << " - " << -c.imag << "i";
        return COUT;
    }

    // Overload + operator to add two complex numbers
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator to subtract two complex numbers
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload / operator to divide two complex numbers
    Complex operator/(const Complex& other) {
        // Complex division formula:
        // (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)

        double denominator = other.real * other.real + other.imag * other.imag;
        
        if (denominator == 0) {
            throw runtime_error("Division by zero in complex division.");
        }

        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;

        return Complex(newReal, newImag);
    }
};

int main() {
    // Create two complex numbers c1 = 4 + 5i and c2 = 2 - 3i
    Complex c1(4, 5), c2(2, -3);

    // Display the complex numbers
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    // Display the result of addition
    cout << "Sum = " << c1 + c2 << endl;

    // Display the result of subtraction
    cout << "Difference = " << c1 - c2 << endl;

    // Display the result of division
    cout << "Quotient = " << c1 / c2 << endl;

    return 0;
}
