#include <iostream>
using namespace std;

// Enter the number: 1634
// 1634 is an ArmStrong Number

// Enter the number: 432
// 432 is Not an ArmStrong Number

void armstrongNumber(int n){
    int num = n, count = 0, armNum=0;
    while(num > 0){
        num /= 10;
        count++;
    }
    num=n;
    while(num>0){
        int temp = num%10;
        int res=1;
        for(int i=0; i<count; i++){
            res*=temp;
        }
        armNum+=res;
        num/=10;
    }
    if(n==armNum){
        cout << n << " is an ArmStrong Number" << endl;
    }else{
        cout << n << " is Not an ArmStrong Number" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    armstrongNumber(n);
}