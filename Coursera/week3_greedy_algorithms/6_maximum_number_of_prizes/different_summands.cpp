#include <iostream>
#include <vector>

using std::vector;

/*
You are organizing a funny competition for children. As a prize fund you have π
candies. You would like to use these candies for top π places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to find the largest
value of π for which it is possible.

The goal of this problem is to represent a given positive integer π as a sum of as many pairwise
distinct positive integers as possible. That is, to find the maximum π such that π can be written as
π1 + π2 + Β· Β· Β· + ππ where π1, . . . , ππ are positive integers and ππ ΜΈ= ππ for all 1 β€ π < π β€ π.
*/

void optimal_summands(int n, vector<int>& summands) {
  summands.push_back(0);
  // Base case -> n = 2, n = 1
  if (n <= 2) {
    summands.push_back(n);
    return;
  }
  int i = 1;
  int running_sum = 0;
  while (running_sum < n) {
    if (running_sum + i < n) {
      summands.push_back(i);
      running_sum += i;
      i++;
    } 
    else if ((n - running_sum) > summands[summands.size() - 1]) {
      //std::cout << "control 1" << '\n';
      //std::cout << "n = " << n << ' ' << "running_sum = " << running_sum << '\n';
      //std::cout << "n - running_sum = " << n - running_sum << '\n';
      summands.push_back(n - running_sum);
      break;
    }
    else{
      //std::cout << "control 2" << '\n';
      //std::cout << "n = " << n << ' ' << "running_sum = " << running_sum << '\n';
      //std::cout << "n - running_sum = " << n - running_sum << '\n';
      summands[summands.size() - 1] = (n - (running_sum - summands.back()));
      break;
    }
  };
  

}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands;
  optimal_summands(n, summands);

  // Print the vector
  //for (int i = 0; i < summands.size(); ++i) {
  //  std::cout << summands[i] << " ";
  //}
  //std::cout << '\n';

  std::cout << summands.size()-1 << '\n';

  for (size_t i = 1; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
