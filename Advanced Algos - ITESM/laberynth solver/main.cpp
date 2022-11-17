/* 
Using the "backtracking" and "branch and bound" programming techniques, write a program that solves a maze.

The program receives two integers M and N, followed by M lines of N boolean values (0|1) separated by a space, by standard input representing the maze. A 1 represents a square where it is possible to move, a 0 is a square that cannot be passed.
The origin or start square is always the square (0,0) and the exit or goal is always the square (M-1, N-1)
The output of the program is two arrays of boolean values (0|1) that represent the path out of the maze.

The first array represents the path found by the "backtracking" technique and the second array represents the path found by the "branch and bound" technique.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solveUsingBranchAndBound (vector<vector<int>> maze, int m, int n);
bool solveUsingBranchAndBoundUtil (vector<vector<int>> maze, int m, int n, int x, int y, vector<vector<int>> &solution);
bool isSafe (vector<vector<int>> maze, int m, int n, int x, int y);

vector<vector<int>> solveUsingBranchAndBound (vector<vector<int>> maze, int m, int n) {
    vector<vector<int>> solution;
    vector<int> row;
    for (int i = 0; i < n; i++) {
        row.push_back(0);
    }
    for (int i = 0; i < m; i++) {
        solution.push_back(row);
    }
    solution[0][0] = 1;
    if (solveUsingBranchAndBoundUtil(maze, m, n, 0, 0, solution) == false) {
        cout << "No solution exists" << endl;
        return {};
    }
    return solution;
}

bool solveUsingBranchAndBoundUtil (vector<vector<int>> maze, int m, int n, int x, int y, vector<vector<int>> &solution) {
    if (x == m - 1 && y == n - 1) {
        return true;
    }
    if (isSafe(maze, m, n, x + 1, y)) {
        solution[x + 1][y] = 1;
        if (solveUsingBranchAndBoundUtil(maze, m, n, x + 1, y, solution)) {
            return true;
        }
        solution[x + 1][y] = 0;
    }
    if (isSafe(maze, m, n, x, y + 1)) {
        solution[x][y + 1] = 1;
        if (solveUsingBranchAndBoundUtil(maze, m, n, x, y + 1, solution)) {
            return true;
        }
        solution[x][y + 1] = 0;
    }
    return false;
}

bool solveUsingBacktracking (vector<vector<int>> maze, vector<vector<int>> &solution, int m, int n, int x, int y){
    // Base case
    if (x == m - 1 && y == n - 1) {
        solution[x][y] = 1;
        return true;
    }
    // Recursive case
    if (isSafe(maze, m, n, x, y)) {
        solution[x][y] = 1;
        if (solveUsingBacktracking(maze, solution, m, n, x + 1, y)) {
            return true;
        }
        if (solveUsingBacktracking(maze, solution, m, n, x, y + 1)) {
            return true;
        }
        solution[x][y] = 0;
    }
    return false;
}

bool isSafe (vector<vector<int>> maze, int m, int n, int x, int y) {
    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1) {
        return true;
    }
    return false;
}

void printSolution (vector<vector<int>> solution, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
        cout << '\n';
    }
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> maze;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        maze.push_back(row);
    }
    cout << '\n';
    vector<vector<int>> solution1 = solveUsingBranchAndBound(maze, m, n);
    printSolution(solution1, m, n);
    cout << '\n';
    vector<vector<int>> solution2(n, vector<int>(m, 0));
    solveUsingBacktracking(maze, solution2, m, n, 0, 0);
    printSolution(solution2, m, n);
    return 0;
}
    