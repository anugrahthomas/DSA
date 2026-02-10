#include <iostream>
using namespace std;

// Enter the number: 5
// 12345
// 1234
// 123
// 12
// 1

void printPattern(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout << j;
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