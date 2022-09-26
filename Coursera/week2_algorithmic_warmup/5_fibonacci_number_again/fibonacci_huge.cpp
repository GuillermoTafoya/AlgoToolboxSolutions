#include <iostream>

// The pisano period is the period with which the sequence of Fibonacci numbers taken modulo n repeats.
long get_pisano_period(long long m) {
    long long previous = 0;
    long long current  = 1;
    long long i        = 0;
    while (true) {
        long long next = (previous + current) % m;
        previous = current;
        current = next;
        i++;
        if (previous == 0 && current == 1) {
            return i;
        }
    }
    return 0;
}

int get_fibonacci_huge(long long n, long long m) {
    n = n % get_pisano_period(m);
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    int previous = 0;
    int current  = 1;

    // Mod sum
    // (a + b) mod m = ((a mod m) + (b mod m)) mod m

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous % m;
        previous = current % m;
        current = (tmp_previous + current) % m;
    }

    return current;
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
