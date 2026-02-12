#include <iostream>
using namespace std;


// Enter the number: 5
// 5 4 3 2 1

void recurrsion(int n){
    if(n==0) return;
    cout << n << " ";
    recurrsion(n-1);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    recurrsion(n);
}