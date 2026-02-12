#include <iostream>
using namespace std;


// Enter the number: 5
// The Sum is: 15


// this is the functional way witout using extra paramter
int recurrsion(int n){
    if(n==0) return 0;
    return n + recurrsion(n-1);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int sum = recurrsion(n);
    cout << "The Sum is: "<< sum;
}