// there are many solutions of finding gcd of two numbers
// 1. simple factorization means finding all factors which is divide both numbers then taking the maximum of them (loop 1 to min(a,b) or sqrt(min(a,b)) other loop min(a,b) to 1)
// 2. Euclidean algorithm which is the most efficient way to find gcd of two numbers
// euclidean states that gcd(a,b) = gcd(a-b, b) if a>b
// further simply this can be written as gcd(a,b) = gcd(a%b, b) if a>b

#include <iostream>
using namespace std;

// Enter a: 36
// Enter b: 60
// GCD of 36 and 60 is: 12

int minimum(int a, int b) {
    return (a>b) ? b : a;
}

int maximum(int a, int b) {
    return (a>b) ? a : b;
}

int gcd(int a, int b) { // this is a bit of code because in this we have to check min and max everytime
    if(a==0) return b;
    int min = minimum(a,b);
    int max = maximum(a,b);
    return gcd(max%min, min);
}

int gcdR(int a, int b) {
    if(b==0) return a;
    return gcdR(b, a%b);
}

int gcdI(int a, int b) {
    while(b!=0) {
        int temp = a;
        a = b;
        b = a%b;
    }
    return a;
}

int main(){
    int a,b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    int result = gcdI(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result;
}