#include <iostream>
using namespace std;

// Enter the number: 74823742
// The count of digit is: 8

int digitCount(int n){
    int num = n, count = 0;
    while(num > 0){
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int result = digitCount(n);
    cout << "The count of digit is: " << result;
}