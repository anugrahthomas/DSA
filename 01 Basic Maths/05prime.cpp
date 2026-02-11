#include <iostream>
using namespace std;

bool isPrime(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    int n = 2;
    if(isPrime(n)) {
        cout << n << " is Prime" << endl;
    }else {
        cout << n << " is not Prime" << endl;
    }
}