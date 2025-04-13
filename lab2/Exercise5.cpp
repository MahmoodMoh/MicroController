#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int arr1[size] = {1, 4, 7, 10, 15};
    int arr2[size];

    // Pointer starts at the end of arr1
    int* ptr = &arr1[size - 1];

    // Traverse and copy to arr2
    for (int i = 0; i < size; i++) {
        arr2[i] = *ptr;
        ptr--; // move pointer to the left
    }

    // Print the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
