// Given a set of numbers and a limit S, find the subset with the maximum sum that is less than or equal to S.
// Time complexity: O(2^(n/2) * n)
// Space complexity: O(2^(n/2))

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solve using backtracking
int solve(vector<int> &v, int n, int s, int i, int sum) {
    if (i == n) {
        return sum;
    }
    int ans = solve(v, n, s, i + 1, sum);
    if (sum + v[i] <= s) {
        ans = max(ans, solve(v, n, s, i + 1, sum + v[i]));
    }
    return ans;
}

int main() {
    int n, S;
    // Read input
    // 6 42
    // 45 34 4 12 5 2
    // Expected output: 41
    // Read input
    // 6 10
    // 3 34 4 12 5 2
    // Expected output: 10
    cin >> n >> S;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> subsets1;
    
    cout << solve(arr, n, S, 0, 0) << '\n';
    return 0;
}