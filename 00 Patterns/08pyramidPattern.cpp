#include <iostream>
using namespace std;


// Note: there is many solution of one problem like here we can solve by  i=0; j=0; also using 2loops and 1loop 
// Enter the number: 5
//     *
//    ***
//   *****
//  *******
// *********

void printPattern(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<n-i+1; j++){
            cout << " ";
        }
        
        // for(int j=1; j<=2*i-1; j++){ // only add this loop after above spacing
        //     cout << "*";
        // }
        
        for(int j=1; j<=i; j++){ 
            cout << "*";
        }
        for(int j=1; j<i; j++){
            cout << "*";
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