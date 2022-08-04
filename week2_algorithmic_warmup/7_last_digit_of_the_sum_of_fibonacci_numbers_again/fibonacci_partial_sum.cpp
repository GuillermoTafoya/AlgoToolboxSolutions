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

int get_fibonacci_partial_sum(long long from, long long to) {
    to = to % get_pisano_period(10);
    from = from % get_pisano_period(10);
    int sum = 0;
    int current = 0;
    int next  = 1;

    // Mod sum
    // (a + b) mod m = ((a mod m) + (b mod m)) mod m

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum = (sum + current) % 10;
        }

        int new_current = next % 10;
        next = (next + current) % 10;
        current = new_current % 10;
    }

    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
