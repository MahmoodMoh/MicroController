#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countVowels(const string& str) {
    int count = 0;
    string vowels = "AEIOUaeiou";
    for (char c: str) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}
int main(){
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string upperStr = input;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), :: toupper);
    cout << "Uppercase: " <<upperStr<< endl;

    int vowelCount = countVowels(input);
    cout << "Number of vowels: " << vowelCount << endl;

    string reversedStr = input;
    reverse(reversedStr.begin(), reversedStr.end());
    cout << "Reversed: " << reversedStr <<endl;
    return 0;
}