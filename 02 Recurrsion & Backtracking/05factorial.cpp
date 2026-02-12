#include <iostream>
using namespace std;


// Enter the number: 5
// The Factoral of 5 is: 120

int recurrsion(int n){
    if(n==0) return 1;
    return n * recurrsion(n-1);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int factorial = recurrsion(n);
    cout << "The Factoral of "<< n << " is: "<< factorial;
}