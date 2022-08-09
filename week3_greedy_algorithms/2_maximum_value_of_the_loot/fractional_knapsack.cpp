#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  if (capacity == 0) {
    return 0.0;
  }
  int m = 0; // index of the maximum value
  for (int i = 0; i < values.size(); i++) {
    if (values[i] > values[m]) {
      m = i;
    }
  }
  double amount = std::min(capacity, weights[m]);
  value += amount * values[m];
  weights.erase(weights.begin() + m);
  values.erase(values.begin() + m);
  return value + get_optimal_value(capacity, weights, values);
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
