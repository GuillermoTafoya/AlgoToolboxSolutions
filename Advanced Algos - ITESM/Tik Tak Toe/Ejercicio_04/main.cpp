/*
Write a program that uses exhaustive search to solve the partition
optimization problem. Allow the user to create a list of random weights
between the limits set by the user. 

Also allow the user to check a box indicating whether the algorithm will use: short circuit or stop early.
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
    cout << "Short circuit (1 or 0): ";
    cin >> shortCircuit;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minWeight, maxWeight);

    for (int i = 0; i < numWeights; i++) {
        weights.push_back(dis(gen));
    }

    cout << "Weights: ";
    printVector(weights);

    for (int i = 1; i < (1 << numWeights); i++) {
        vector<int> partition1;
        vector<int> partition2;
        for (int j = 0; j < numWeights; j++) {
            if (i & (1 << j)) {
                partition1.push_back(weights[j]);
            }
            else {
                partition2.push_back(weights[j]);
            }
        }
        if (shortCircuit) {
            if (partitions.count(sumVector(partition1)) == 0) {
                partitions[sumVector(partition1)] = { partition1, partition2 };
            }
            else {
                partitions[sumVector(partition1)].push_back(partition1);
                partitions[sumVector(partition1)].push_back(partition2);
            }
        }
        else {
            partitions[abs(sumVector(partition1) - sumVector(partition2))].push_back(partition1);
            partitions[abs(sumVector(partition1) - sumVector(partition2))].push_back(partition2);
        }
    }
    printMap(partitions);
    return 0;
}
