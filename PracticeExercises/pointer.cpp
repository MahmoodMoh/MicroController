#include <iostream>
using namespace std;

void printNumber(int* numberPtr){
    cout <<*numberPtr<< endl;
}
void printNumber(char* charPtr){
    cout <<*charPtr<< endl;
}
void print(void*ptr, char type) {
    switch (type) {
        case 'i': cout<< *((int*)ptr) << endl; break;
        case 'c': cout << *((char*)ptr) << endl; break;
    }
}
int main(){
    /*
    string bowl = "grapes";
    cout << bowl << endl;
    string* ptr = &bowl;
    cout << ptr << endl;
    cout << *ptr << endl;
    *ptr = "apples, apples";
    cout<<bowl<<endl;
    */
   // Void pointer: can hold the address of any type of variables

   int number = 5;
   char letter = 'a';
   //printNumber(&number);
   print(&number, 'i');
   print(&letter, 'c');






    system("pause>0");


}