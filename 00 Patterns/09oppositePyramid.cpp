#include <iostream>
using namespace std;

// Enter the number: 5
// *********
//  *******
//   *****
//    ***
//     *

void printPattern(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            cout<<" ";
        }
        // for(int j=1; j<=2*n-2*i+1; j++){ // complex to think or we can use 2loop to built 2sides
        //     cout << "*";
        // }
        for(int j=1; j<=n-i+1; j++){
            cout<<"*";
        }
        for(int j=1; j<n-i+1; j++){
            cout<<"*";
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