// Recurssion is a process that a function invokes itself
#include <iostream>
using namespace std;

int recursive_sum(int m, int n) {
    if (m==n)
    return m;
    return m + recursive_sum(m + 1, n);
}
// Sum numbers between m-n
int main(){
// using loops
int m = 2, n = 4;
cout << "Sum = " << recursive_sum(m, n);
/*int sum = 0;
for(int i = m; i <= n; i++) {
    sum += i;

}
cout << "Sum= " << sum;*/

system ("pause>0");
}