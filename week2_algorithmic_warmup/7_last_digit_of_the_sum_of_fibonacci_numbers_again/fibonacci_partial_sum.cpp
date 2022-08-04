#include <iostream>
#include <vector>
using std::vector;

int get_fibonacci_partial_sum_naive(long long from, long long to) {
    int sum = 0;

    int current = 0;
    int next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum = (sum + current) % 10;
        }

        int new_current = next;
        next = (next + current) % 10;
        current = new_current;
    }

    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
