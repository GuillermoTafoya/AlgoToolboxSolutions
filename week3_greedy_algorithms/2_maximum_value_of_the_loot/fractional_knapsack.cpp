#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Item {
public:
    int value, weight;
    Item(double value, double weight): value(value), weight(weight) {}
    Item(): value(1), weight(1) {}
};
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2; // Compile in g++
}

double get_optimal_value(int capacity, vector<Item> arr, int n) {

  std::sort(arr.begin(), arr.end(), cmp);

  double value = 0.0;
  for (int i = 0; i < n; i++) {
      if (arr[i].weight <= capacity) {
          capacity -= arr[i].weight;
          value += arr[i].value;
      }else {
            value += arr[i].value * ((double)capacity / (double)arr[i].weight);
            break;
        }
    }
    return value;
}

int main() {
  int n;
  int capacity;
  int value;
  int weight;
  std::cin >> n >> capacity;
  vector<Item> items(n);
  for (int i = 0; i < n; i++) {
    std::cin >> value >> weight;
    items[i] = Item(value, weight);
  }
  double optimal_value = get_optimal_value(capacity, items, n);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
