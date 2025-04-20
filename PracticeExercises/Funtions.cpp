// Functions, why?
//Functions make the code reusable. Makes life and coding easier. 
#include <iostream>
using namespace std;

/* Functions Parameters or arguments: 
Sometimes a function needs to receive a certain value or variable, then perform a certain task on that value*/

void introduceMe(string name, string city, int age=0){ // Inside the bracket contains the parameter
    cout <<"My name is " << name << endl;
    cout <<"I am from " << city << endl;
    if (age != 0)
    cout <<"I am " << age << " years old" << endl;


}
int main(){
    /*introduceMe("MM", "Vantaa", 31);
    cout << endl << endl;
    introduceMe("Khan", "Helsinki", 27);*/

    string name1, city1;
    int age1;
    cout << "Name: ";
    cin >> name1;

    cout << "City: ";
    cin >> city1;
    cout << "Age: ";
    cin >> age1;

    introduceMe(name1, city1, age1);
    


    system("pause>0");
}