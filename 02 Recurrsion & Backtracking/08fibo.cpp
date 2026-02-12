#include <iostream>
using namespace std;


// input: 5
// output: 5 4 3 2 2 3 2 
//         The Fibo is: 5

int recurrsion(int n) {
    if(n==0 || n==1) return n;
    return recurrsion(n-1) + recurrsion(n-2);
}

int fibo(int n){
    return recurrsion(n);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    int result = fibo(n);
    cout << "\nThe Fibo is: " << result;
}