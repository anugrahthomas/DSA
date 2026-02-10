#include <iostream>
using namespace std;

// Enter the number: 5
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA

void printPattern(int n){
    for(int i=0; i<n; i++){
        for(int j=i; j<n-1; j++){
            cout << " ";
        }
        for(char ch = 'A'; ch<='A'+i; ch++){
            cout << ch;
        }
        for(char ch = 'A'+i-1; ch>='A'; ch--){
            cout << ch;
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