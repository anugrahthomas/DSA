#include <iostream>
using namespace std;

// Enter the number: 5
// E
// DE
// CDE
// BCDE
// ABCDE

void printPattern(int n){
    for(int i=0; i<n; i++){
        char ch = 'A' + (n-i-1);
        for(int j=0; j<=i; j++){
            cout << ch++;
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