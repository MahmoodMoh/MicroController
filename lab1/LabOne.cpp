#include <iostream>
#include <string>
using namespace std;

namespace MathOperations {
    int add(int a, int b){
        return a + b;
    }
}

namespace TextOperations {
    string concat(std::string str1, std::string str2){
        return str1 + str2;
    }
}
int main(){
    int sum = MathOperations::add(10, 20);
    cout<<"Sum: " << sum << endl;

    string combinedText = TextOperations::concat("Hello, ", "World!");
    cout <<"Cponcateranted String: " << combinedText << endl;
    return 0;
}