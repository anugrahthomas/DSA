#include <iostream>
using namespace std;

// Enter the number: 5
// 0
// 10
// 010
// 1010
// 01010

void printPattern(int n){
    int pattern = 1;
    for (int i = 0; i < n; i++){
        if(i%2==0){
            pattern = 0;
        }else{
            pattern = 1;
        }
        for(int j=0; j<=i; j++){
            cout << pattern;
            pattern = 1 - pattern;
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