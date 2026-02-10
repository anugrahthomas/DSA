#include <iostream>
using namespace std;

// Enter the number: 5
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********


void printPattern(int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cout << "*";
        }
        for(int j=0; j<2*i; j++){
            cout << " ";
        }
        for(int j=i; j<n; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        for(int j=0; j<2*n-2*i-2; j++){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printPattern(n);
}