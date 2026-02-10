#include <iostream>
using namespace std;

// Enter the number: 4
// 1      1
// 12    21
// 123  321
// 12344321

void printPattern(int n){
    for (int i = 1; i <= n; i++){
        for(int j=1; j<=i; j++){
            cout << j;
        }
        for(int j=1; j<=2*n-2*i; j++){
            cout << " ";
        }
        for(int j=i; j>0; j--){
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