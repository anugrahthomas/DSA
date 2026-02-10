#include <iostream>
using namespace std;

// Enter the number: 5
// A
// BB
// CCC
// DDDD
// EEEEE

void printPattern(int n){
    char ch = 'A';
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << ch;
        }
        ch++;
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printPattern(n);
}