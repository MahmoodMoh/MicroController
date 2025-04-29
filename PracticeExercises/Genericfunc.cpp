// Generic functions and templates

#include <iostream>
using namespace std;

template<typename T> // T is generic data type, it can be used with different data type
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main (){
    // Integer type
    int a = 5, b = 7;
    cout << a << " - " << b << endl;
    Swap<int>(a, b);
    cout << a << " - " << b << endl; 

    // Character type
    char c = 'c', d = 'd';
    cout << c << " - " << d << endl;
    Swap<char>(c, d);
    cout << c << " - " << d << endl;



system("pause>0");
}