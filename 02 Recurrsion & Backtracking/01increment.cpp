#include <iostream>
using namespace std;


// Enter the number: 5
// 1 2 3 4 5

void recurrsion(int n){
    if(n==0) return;
    recurrsion(n-1);
    cout << n << " ";
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    recurrsion(n);
}