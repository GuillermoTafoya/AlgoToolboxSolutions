/*
Use the program written for Exercise 4 to solve the partition problem
using an exhaustive search and Branch and Bound with the values 1 through
5, 1 through 6, 1 through 7, and so on up to 1 through 25. Then, plot the
number of nodes visited against the number of weights that have been partitioned 
for the two methods. Finally, on a separate graph, show the logarithm of the
number of nodes visited versus the number of weights of the results.
What can you conclude about the number of nodes visited for the two methods?
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

    cout << "Enter number of weights: ";
    cin >> numWeights;
    cout << "Enter minimum weight: ";
    cin >> minWeight;
    cout << "Enter maximum weight: ";
    cin >> maxWeight;
    cout << "Short circuit? (0 = no, 1 = yes): ";
    cin >> shortCircuit;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minWeight, maxWeight);

    for (int i = 0; i < numWeights; i++) {
        weights.push_back(dis(gen));
    }

    cout << "Weights: ";
    printVector(weights);

    int totalWeight = sumVector(weights);
    maxWeight = totalWeight / 2;

    if (totalWeight % 2 == 0) {
        cout << "Total weight: " << totalWeight << endl;
        cout << "Max weight: " << maxWeight << endl;
        cout << "Short circuit: " << shortCircuit << endl;
    } else {
        cout << "Cannot partition weights" << endl;
    }

    return 0;
}