/*
Extend the program written for Exercise 7 to use improved heuristics to find the solution.
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
    printVector(weights);

    int sum = sumVector(weights);

    for (int i = 1; i < (1 << weights.size()); i++) {
        vector<int> partition;
        for (int j = 0; j < weights.size(); j++) {
            if (i & (1 << j)) {
                partition.push_back(weights[j]);
            }
        }
        int partitionSum = sumVector(partition);
        if (partitions.count(partitionSum) == 0) {
            vector<vector<int>> newPartitions;
            partitions[partitionSum] = newPartitions;
        }
        partitions[partitionSum].push_back(partition);
    }

    int bestSum = 0;
    for (auto i = partitions.begin(); i != partitions.end(); i++) {
        if (i->first > bestSum && i->first <= sum / 2) {
            bestSum = i->first;
        }
    }

    printMap(partitions);

    cout << "Best sum: " << bestSum << endl;

    return 0;
}