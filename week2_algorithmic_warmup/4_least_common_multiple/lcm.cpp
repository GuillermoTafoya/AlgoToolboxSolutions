#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_optimal(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd_optimal(b, a % b);
}

long long gcd_steins_algorithm(long long a, long long b) {
  if (a == 0)
      return b;
  if (b == 0)
      return a;

  int k;
  for (k = 0; ((a | b) & 1) == 0; ++k)
  {
      a >>= 1;
      b >>= 1;
  }
  while ((a & 1) == 0)
      a >>= 1;
  do
  {
      while ((b & 1) == 0)
          b >>= 1;
      if (a > b)
          std::swap(a, b);
      b -= a;
  } while (b != 0);
  return a << k;
}

long long lcm_optimal(long long a, long long b) {
  return (a * b) / gcd_steins_algorithm(a, b);
}

void stress_test(int n){
  for (int i = 0; i < n; ++i) {
    int a = rand() % 100000000 + 2;
    int b = rand() % 100000000 + 2;
    long long c = lcm_optimal(a, b);
    long long d = lcm_naive(a, b);
    std::cout << "lcm(" << a << ", " << b << ") = " << c << '\n';
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_optimal(a, b) << std::endl;
  //stress_test(100);
  return 0;
}
