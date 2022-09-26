#include <algorithm>
#include <iostream>
#include <vector>

/*
You have 𝑛 ads to place on a popular Internet page. For each ad, you know how
much is the advertiser willing to pay for one click on this ad. You have set up 𝑛
slots on your page and estimated the expected number of clicks per day for each
slot. Now, your goal is to distribute the ads among the slots to maximize the
total revenue.

Given two sequences 𝑎1, 𝑎2, . . . , 𝑎𝑛 (𝑎𝑖
is the profit per click of the 𝑖-th ad) and 𝑏1, 𝑏2, . . . , 𝑏𝑛 (𝑏𝑖
is the average number of clicks per day of the 𝑖-th slot), we need to partition
them into 𝑛 pairs (𝑎𝑖, 𝑏𝑗) such that the sum of their products is maximized.
*/

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end(), std::greater<int>());
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
