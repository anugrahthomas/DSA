#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Enter the number: 36
// The Divisors are: 1 2 3 4 6 9 12 18 36

void divisors(int n){
    vector<int> arr;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            arr.push_back(i);
            if(n/i != i){
                arr.push_back(n/i);
            }
        }
    }
    sort(arr.begin(), arr.end());
    cout << "The Divisors are: ";
    for(auto it:arr) cout<< it <<" ";
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    divisors(n);
}