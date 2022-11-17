// A graph class representation using adjacency list

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Graph
{
private:
    int V; // number of vertices
    map<char, list<char> > adjList; // adjacency list
    // A: [B, C, D]
    // B: [A, C]
    // C: [A, B, D]
public:
    Graph() {
        V = 0;
    }
    void loadGraph(string filename);
    void printGraph();
    void BFS(char s);
    void DFS(char s);

};
    

void Graph::loadGraph(string filename){
    // the txt contains:
    // 1st line: number of vertices
    // next lines n lines: charactor of all possible vertices
    // next lines: adjacency matrix of integers 0 or 1
    ifstream infile(filename);
    string line;
    int i = 0;
    vector<char> vertices; // store all vertices [A, B, C, D] 1 0 1 1
    while (getline(infile, line))
    {
        if (i == 0) {
            V = stoi(line);
            i++;
            continue;
        }
        if (i <= V) {
            adjList[line[0]] = list<char>();
            // A: []
            // B: []
            // C: []
            // D: []
            i++;
            vertices.push_back(line[0]);
            continue;
        }
        if (i > V) {
            // 1 0 0 1
            // 0 1 0 0
            // 0 0 1 0
            // 1 0 0 1
            // each line has space separated integers
            // line.split like python
            istringstream iss(line);
            int j = 0;
            for (string s; iss >> s; ) {
                if (s == "1") {
                    adjList[vertices[i-V-1]].push_back(vertices[j]);
                    // A: [D]
                    // B: []
                    // C: []
                    // D: [A]
                }
                j++;
                }

        }
        i++;
    }
}

void Graph::printGraph() {
    for (auto i : adjList) {
        cout << i.first << ": ";
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << '\n';
    }
}

void Graph::BFS(char s) {
    // create a visited array
    map<char, bool> visited;
    for (auto i : adjList) {
        visited[i.first] = false;
    }
    // create a queue for BFS
    queue<char> q;
    // mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        // dequeue a vertex from queue and print it
        s = q.front();
        cout << s << " ";
        q.pop();
        // get all adjacent vertices of the dequeued vertex s
        // if an adjacent has not been visited, then mark it visited and enqueue it
        for (auto i : adjList[s]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void Graph::DFS(char s) {
    // create a visited array
    map<char, bool> visited;
    for (auto i : adjList) {
        visited[i.first] = false;
    }
    // stack for DFS
    stack<char> st;
    // mark the current node as visited and enqueue it
    visited[s] = true;
    st.push(s);
    while (!st.empty()) {
        // dequeue a vertex from queue and print it
        s = st.top();
        cout << s << " ";
        st.pop();
        // get all adjacent vertices of the dequeued vertex s
        // if an adjacent has not been visited, then mark it visited and enqueue it
        for (auto i : adjList[s]) {
            if (!visited[i]) {
                visited[i] = true;
                st.push(i);
            }
        }
    }
}

int main()
{
    Graph g;
    g.loadGraph("input.txt");
    g.printGraph();
    g.BFS('A');
    cout << '\n';
    g.DFS('A');
}