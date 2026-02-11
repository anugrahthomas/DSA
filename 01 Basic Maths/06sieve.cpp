// Sieve of Eratosthenes-> gives primes between 2 to n
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<bool> &primes) { // time: O(n loglogn), space: O(n)
    if(n<=1) return;
    primes[0] = primes[1] = false;

    for(int i=2; i*i<=n; i++) {
        if(primes[i] == true) {
            for(int j=i*i; j<=n; j+=i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    int n = 1000;
    vector<bool> primes(n+1, true);
    sieve(n, primes);
    for(int i=0; i<primes.size(); i++) {
        if(primes[i] == true) {
            cout << i << " ";
        }
    }
}

// Error while solve i*i<=n not same as i<=sqrt(n), because 6.9999999, precision error
