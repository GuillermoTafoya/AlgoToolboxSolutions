// Implement the astar algorithm to return all the best paths

// We get an input of a graph. We start on the top left corner and we want to get to the bottom right corner.
// We can only move down or right.
// We want to find all the shortest path.

/*
Input: 
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR
DRDDRR
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    int x;
    int y;
    int dist;
    string path;
    Node(int x, int y, int dist, string path) : x(x), y(y), dist(dist), path(path) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->dist > b->dist;
    }
};

int main() {
    int N;
    cin >> N;
    vector<vector<int>> m(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
    priority_queue<Node*, vector<Node*>, Compare> pq;
    pq.push(new Node(0, 0, 0, ""));
    while (!pq.empty()) {
        Node* node = pq.top();
        pq.pop();
        if (node->x == N - 1 && node->y == N - 1) {
            cout << node->path << endl;
        }
        if (node->x + 1 < N && m[node->x + 1][node->y] == 1) {
            pq.push(new Node(node->x + 1, node->y, node->dist + 1, node->path + "D"));
        }
        if (node->y + 1 < N && m[node->x][node->y + 1] == 1) {
            pq.push(new Node(node->x, node->y + 1, node->dist + 1, node->path + "R"));
        }
    }
    return 0;
}

// N = 4
// 1 0 0 0
// 1 1 0 1
// 1 1 0 0
// 0 1 1 1