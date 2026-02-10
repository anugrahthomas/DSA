#include <iostream>
using namespace std;

// Enter the number: 5
// 555555555
// 544444445
// 543333345
// 543222345
// 543212345
// 543222345
// 543333345
// 544444445
// 555555555

void printPattern(int n){
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int top = i;
            int left = j;
            int bottom = (2*n-2) - i;
            int right = (2*n-2) - j;
            cout << n-min(min(top, bottom), min(left, right));
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