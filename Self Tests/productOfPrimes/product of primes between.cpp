// Get the product of all primes between l and r

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    int l, r;
    cin >> l >> r;
    long long product = 1;
    for (int i = l; i <= r; i++) {
        if (isPrime(i)) {
            product *= i;
        }
    }
    cout << product;
    return 0;
}