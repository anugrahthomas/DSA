#include <iostream>
using namespace std;

// Enter the number: 5
// ABCDE
// ABCD
// ABC
// AB
// A

void printPattern(int n){
    for (int i = 0; i < n; i++){
        for(char c='A'; c <='A'+(n-i-1); c++){
            cout << c;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printPattern(n);
}