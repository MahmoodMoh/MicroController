// Nesting loop

#include <iostream>

using namespace std;

int main (){
    // Prompt the user to enter three grades between 1 and 5, then find the average between those grades
    int grade, sum = 0;
    for(int i = 0; i < 3; i++){
        do{
            cout <<"Enter grade " << i + 1 << ": ";
            cin >> grade;
            
        }while(grade < 1 || grade > 3);
        sum += grade;
    }
    cout << "Sum = " << sum << endl;
    cout << "Avg grade = " << sum / 3.0 << endl;

    system("pause>0");
}