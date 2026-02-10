#include <iostream>
using namespace std;

// Enter the number: 5
// A
// AB
// ABC
// ABCD
// ABCDE

void printPattern(int n){
    for (int i = 0; i < n; i++){
        for(char c='A'; c <='A'+i; c++){
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