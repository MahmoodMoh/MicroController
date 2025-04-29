// pointers and arrays
#include <iostream>
using namespace std;

/*int getMin(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++){
        if (numbers[i] < min) {
            min = numbers[i];
        }
        
    }
    return min;
}
int getMax(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        
    }
    return max;
}*/
int getMinAndMax(int numbers[], int size){
     int min = numbers[0];
     int max = numbers[0];
    for (int i = 1; i <= size; i++) {
        if (numbers[i] < min)
        min = numbers[i];

        else if(numbers[i] > max)
        max = numbers[i];
        

    }
    return min;
    return max;
}

int main(){

    int numbers[5] = {5,3,-2, 4,7};
    cout << "Max and Min are: " << getMinAndMax(numbers, 5) << endl;
    /*cout << "Min is " << getMin(numbers, 5) << endl;
    cout << " Max is: " << getMax(numbers, 5) << endl;
    
    /*int luckyNumbers[5] = {2,3,5,7,9};
    cout<< luckyNumbers << endl;
    cout << &luckyNumbers[0] << endl;
    cout << luckyNumbers[2] << endl;  //Prints out 5 by dereferencing 2 inside the bracket
    cout << *(luckyNumbers + 2) << endl; // Prints out 5 
    */

    /*int luckyNumbers [5];

    for (int i = 0; i <= 4; i++){
        cout << "Number: ";
        cin >> luckyNumbers[i];
    }

    for (int i = 0; i <= 4; i++) {
        cout<< *(luckyNumbers + i) << "  "; 
    }
*/


    system("pause>0");
    return 0;
}