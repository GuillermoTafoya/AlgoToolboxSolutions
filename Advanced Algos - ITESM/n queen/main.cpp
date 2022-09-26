// Put N Queens on a NxN chessboard so that no two queens attack each other

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Check if a queen can be placed in the given row and column
bool canPlace(vector<vector<int>> &v, int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (v[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (v[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < v.size(); i--, j++) {
        if (v[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Solve using backtracking
vector<vector<int>> solve(vector<vector<int>> &v, int n, int row) {
    // If all queens are placed, return the solution
    if (row == n) {
        return v;
    }

    // Try to place a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        // Check if the queen can be placed in the current row and column
        if (canPlace(v, row, col)) {
            // Place the queen
            v[row][col] = 1;

            // Solve the remaining problem
            vector<vector<int>> solution = solve(v, n, row + 1);

            // If a solution was found, return it
            if (!solution.empty()) {
                return solution;
            }

            // If no solution was found, remove the queen and try the next column
            v[row][col] = 0;
        }
    }

    // If no solution was found, return an empty vector
    return vector<vector<int>>();
}

int main() {
    int n;
    // Read input
    // 4
    // Expected output:
    // 0 0 1 0
    // 1 0 0 0
    // 0 0 0 1
    // 0 1 0 0
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<int>> solution = solve(v, n, 0);
    if (solution.empty()) {
        cout << "No solution found" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
