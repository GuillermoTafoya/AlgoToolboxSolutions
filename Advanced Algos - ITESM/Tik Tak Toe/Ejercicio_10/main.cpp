/*
Extend the program written for Exercise 8 to use a Hill-Climbing heuristic to find the solution.
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

    sort(weights.begin(), weights.end());

    cout << "Weights: " << endl;
    printVector(weights);

    int sum = sumVector(weights);
    int halfSum = sum / 2;

    vector<int> temp;
    vector<vector<int>> tempPartitions;

    for (int i = 0; i < weights.size(); i++) {
        temp.push_back(weights[i]);
        partitions.insert(pair<int, vector<vector<int>>>(halfSum - weights[i], tempPartitions));
        temp.pop_back();
    }

    for (int i = 0; i < weights.size(); i++) {
        temp.push_back(weights[i]);
        for (int j = i + 1; j < weights.size(); j++) {
            temp.push_back(weights[j]);
            partitions.insert(pair<int, vector<vector<int>>>(halfSum - sumVector(temp), tempPartitions));
            temp.pop_back();
        }
        temp.pop_back();
    }

    cout << "Partitions: " << endl;
    printMap(partitions);

    temp.push_back(weights[0]);
    tempPartitions.push_back(temp);
    partitions[halfSum - weights[0]] = tempPartitions;
    temp.pop_back();

    for (int i = 1; i < weights.size(); i++) {
        temp.push_back(weights[i]);
        for (int j = 0; j < partitions[halfSum - sumVector(temp)].size(); j++) {
            partitions[halfSum - sumVector(temp)][j].push_back(weights[i]);
        }
        temp.pop_back();
    }

    cout << "Partitions: " << endl;
    printMap(partitions);

    int minDiff = halfSum;
    int minDiffKey = halfSum;
    int tempDiff;

    for (auto i = partitions.begin(); i != partitions.end(); i++) {
        tempDiff = halfSum - i->first;
        if (tempDiff < minDiff) {
            minDiff = tempDiff;
            minDiffKey = i->first;
        }
    }

    cout << "Min diff: " << minDiff << endl;
    cout << "Min diff key: " << minDiffKey << endl;

    cout << "Partitions: " << endl;
    printVectorVector(partitions[minDiffKey]);

    return 0;
}