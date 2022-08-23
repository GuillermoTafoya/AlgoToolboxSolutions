#include <iostream>
#include <vector>

std::vector<double> merge(std::vector<double>& left, std::vector<double>& right) {
    // This function merges two sorted vectors into one sorted vector.
    // This is intended to be used by the mergeSort function.
    std::vector<double> result;
    while (!left.empty() && !right.empty()) {
        if (left.front() > right.front()) {
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
    // This function sorts a vector using the merge sort algorithm.}
    if (input.size() == 1) {
        return input;
    }
    // This is the divide step of the merge sort algorithm.
    int middle = input.size() / 2;
    // This is the conquer step of the merge sort algorithm.
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
    /*
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
    */
    input = mergeSort(input);
    for (int i = 0; i < n; i++) {
        std::cout << input[i] << ' ';
    }
}
