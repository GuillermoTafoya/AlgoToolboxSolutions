#include <iostream>
#include <vector>
#include <algorithm>

std::vector<double> merge(std::vector<double>& left, std::vector<double>& right) {
    std::vector<double> result;
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            result.push_back(left.front());
            left.erase(left.begin());
        } else {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while (!left.empty()) {
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while (!right.empty()) {
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

std::vector<double> mergeSort(std::vector<double>& input) {
    if (input.size() == 1) {
        return input;
    }
    int middle = input.size() / 2;
    std::vector<double> left(input.begin(), input.begin() + middle);
    std::vector<double> right(input.begin() + middle, input.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<double> input(n);
    for (int i = 0; i < n; i++) {
        double x = 0;
        std::cin >> x;
        input[i] = x;
    }
    std::cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << input[i] << " ";
    }
    std::cout << '\n';
    input = mergeSort(input);
    std::cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << input[i] << ' ';
    }
}
