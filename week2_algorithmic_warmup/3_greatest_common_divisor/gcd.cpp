#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_optimal(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd_optimal(b, a % b);
}

long long gcd_steins_algorithm(long long a, long long b) {
  if (a == b)
    return a;
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (~a & 1){
    if (b & 1)
      return gcd_steins_algorithm(a >> 1, b);
    else
      return gcd_steins_algorithm(a >> 1, b >> 1) << 1;
  }
  if (~b & 1)
    return gcd_steins_algorithm(a, b >> 1);
  if (a > b)
    return gcd_steins_algorithm((a - b) >> 1, b);
  return gcd_steins_algorithm((b - a) >> 1, a);
}

void stress_testing(int n){
  for (int i = 0; i < n; ++i) {
    int a = rand() % 10000000 + 2;
    int b = rand() % 10000000 + 2;
    long long opt = gcd_optimal(a, b);
    long long bitwise = gcd_steins_algorithm(a, b);

    if (opt == bitwise)
      std::cout << "Passed\n";
    else{
      std::cout << a << " " << b << " " << opt << " " << bitwise << '\n';
      std::cout << "Failed\n";
      return;
    }
  }
}

int main() {
  
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_steins_algorithm(a, b) << std::endl;
  /*
  int n;
  std::cin >> n;
  stress_testing(n);*/
  return 0;
}
