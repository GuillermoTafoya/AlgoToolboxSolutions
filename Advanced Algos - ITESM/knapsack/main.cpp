/*
Given an int N, defining the number of items followed by N lines, each representing the value of the item,
followed by N lines representing the weight of the item, followed by an int W, defining the capacity of the knapsack,
return the maximum value of the items that can be put in the knapsack.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> values(N);
    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    int W;
    cin >> W;
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}