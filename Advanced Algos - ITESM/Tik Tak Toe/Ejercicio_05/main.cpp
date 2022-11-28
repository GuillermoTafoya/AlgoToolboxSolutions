/*
Extend the program you wrote for Exercise 4 so that you can perform Branch and Bound with and without short circuit.
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

    for (int i = 1; i < totalWeight; i++) {
        vector<vector<int>> partition;
        vector<int> partition1;
        vector<int> partition2;

        for (int j = 0; j < weights.size(); j++) {
            if (sumVector(partition1) + weights[j] <= i) {
                partition1.push_back(weights[j]);
            } else {
                partition2.push_back(weights[j]);
            }
        }

        if (partition1.size() == weights.size() || partition2.size() == weights.size()) {
            continue;
        }

        partition.push_back(partition1);
        partition.push_back(partition2);

        partitions.insert(pair<int, vector<vector<int>>>(abs(sumVector(partition1) - sumVector(partition2)), partition));

        if (shortCircuit && abs(sumVector(partition1) - sumVector(partition2)) == 0) {
            break;
        }
    }
    printMap(partitions);
    return 0;
}