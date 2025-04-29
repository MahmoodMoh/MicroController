/* 
Arrays: 
*/
#include <iostream>
using namespace std;

int main() {

    float monthsArray[5];

    /*cout << "Enter amount: ";
    cin >> monthsArray[0];
    cin >> monthsArray[1];
    cin >> monthsArray[2];
    cin >> monthsArray[3];
    cin >> monthsArray[4];
    cin >> monthsArray[5];
    */

    float total = 0;

    for (int i = 0; i <= 4; i++){
        cout << "Enter amount for element " << i+1 << endl;
        cin>>monthsArray[i];
        total += monthsArray[i];
    }

    //float total = monthsArray[0] + monthsArray[1] + monthsArray[2] + monthsArray[3] + monthsArray[4] + monthsArray[5];
    float average = total / 5;
    float inTwoYears = average * 24;

    cout << " total: " << total << endl;
    cout << " average: " << average << endl;
    cout << "In Two years: " << inTwoYears << endl;


    return 0;
}