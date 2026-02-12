#include <iostream>
using namespace std;


// Enter the number: 5
// The Sum is: 15


// this is the parameterized way
void recurrsion(int n, int sum){
    if(n==0) {
        cout << "The Sum is: "<< sum;
        return;
    };
    recurrsion(n-1, sum+n);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    recurrsion(n, 0);
}