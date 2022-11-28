/*
What groups would a partition program find if it used the Hill-Climbing heuristic for the weights 7, 9, 7, 6, 7, 7, 5, 7, 5, and 6?
What are the total weights of the groups and the difference between the total weights?
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <random>

using namespace std;

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int sumVector(vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

void printVectorVector(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        printVector(v[i]);
    }
}

void printMap(map<int, vector<vector<int>>> m) {
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << ": " << endl;
        printVectorVector(i->second);
    }
}

int main() {
    int numWeights;
    int minWeight;
    int maxWeight;
    bool shortCircuit;
    vector<int> weights;
    map<int, vector<vector<int>>> partitions;

    // 7, 9, 7, 6, 7, 7, 5, 7, 5, and 6
    weights.push_back(7);
    weights.push_back(9);
    weights.push_back(7);
    weights.push_back(6);
    weights.push_back(7);
    weights.push_back(7);
    weights.push_back(5);
    weights.push_back(7);
    weights.push_back(5);
    weights.push_back(6);

    partitions[sumVector(weights)].push_back(weights);

    printMap(partitions);

    // What are the total weights of the groups and the difference between the total weights?
    int totalWeight = sumVector(weights);
    int difference = abs(totalWeight - totalWeight);

    cout << "Total weight: " << totalWeight << endl;
    cout << "Difference: " << difference << endl;

    return 0;
}