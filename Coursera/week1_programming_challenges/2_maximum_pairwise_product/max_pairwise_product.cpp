#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers, int n) {
    int greatestNum = 0, secondGreatest = 0;
    for (int idx = 0; idx < n; ++idx) {
        if (numbers[idx] > greatestNum) {
            secondGreatest = greatestNum;
            greatestNum = numbers[idx];
        } else if (numbers[idx] > secondGreatest) {
            secondGreatest = numbers[idx];
        }
    }
    return ((long long)greatestNum) * secondGreatest;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers, n) << "\n";
    return 0;
}
