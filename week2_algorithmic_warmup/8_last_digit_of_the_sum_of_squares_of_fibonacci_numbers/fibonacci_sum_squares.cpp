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

int fibonacci_sum_squares_naive(long long n) {
    n = n % get_pisano_period(10);
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int sum      = 1;

    // Mod sum
    // (a + b) mod m = ((a mod m) + (b mod m)) mod m

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum =  (sum + current * current) % 10;
    }

    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
