#include <iostream>
using namespace std;

// Enter the number: 5
// 1
// 22
// 333
// 4444
// 55555

void printPattern(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << i;
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