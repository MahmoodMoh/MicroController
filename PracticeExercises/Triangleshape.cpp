#include <iostream>
#include <iomanip>
using namespace std;

void main(){
    int height, width;
    cout <<"Height: ";
    cin >> height;
    cout <<"Width: ";
    cin >> width;

    char symbol;
    cout <<"Symbol: ";
    cin >> symbol;

    for(int h = 1; h <= height; h++){
        for(int w = 1; w <= h; w++){
            cout << setw(3) <<symbol;
        }
        cout << endl;
    }
    cout <<endl << endl;

    for(int h = height; h >= 1; h--){
        for(int w = 1; w <= h; w++){
            cout << setw(3) <<symbol;
        }
        cout << endl;



        
}
system("pause>0");
}