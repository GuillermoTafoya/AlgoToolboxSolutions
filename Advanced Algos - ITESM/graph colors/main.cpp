/*
Given an int N, followed by N lines representing the adjacency matrix of a graph,
find the minimum number of colors needed to color the graph such that no two adjacent
nodes have the same color.
Then print the colors of each node represented with an int from 0 to N-1.
Example:
Input:
5
0 0 1 0 1
0 0 1 1 1
1 1 0 1 0
0 1 1 0 1
1 1 0 1 0
Output:
Node: 0, Assigned Color: 0
Node: 1, Assigned Color: 0
Node: 2, Assigned Color: 1
Node: 3, Assigned Color: 2
Node: 4, Assigned Color: 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }
    vector<int> colors(N, -1);
    for (int i = 0; i < N; i++) {
        vector<bool> available(N, true);
        for (int j = 0; j < N; j++) {
            if (adj[i][j] == 1 && colors[j] != -1) {
                available[colors[j]] = false;
            }
        }
        for (int j = 0; j < N; j++) {
            if (available[j]) {
                colors[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << "Node: " << i << ", Assigned Color: " << colors[i] << endl;
    }
    return 0;
}
