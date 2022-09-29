#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
There exists 100 diferent tipes of caps each with a unique id from 1 to 100. 
Also there exist 'n' persons each having a collection of a variable number of caps.
To look good on a party, every person wants to wear a cap which he/she doesn't have in his/her collection.
We need to find the total number of ways such that every person is wearing a cap such that no two persons wear the same cap.

Given an input n, followed by n lines each containing k integers representing the id's of caps owned by the ith person.
Find the number of ways such that every person is wearing a cap such that no two persons wear the same cap.
1 <= n <= 10

Input: 
3
5 100 1     // Collection of the 1st person
2           // Collection of the 2nd person
5 100       // Collection of the 3rd person

Output: // All possible ways of wearing caps such that no two persons wear the same cap.
4
(5, 2, 100)
(100, 2, 5)
(1, 2, 5)
(1, 2, 100)
*/

vector<vector<int>> bitmask(vector<vector<int>> &caps, int n){
    vector<vector<int>> result

int main(){
    int n;
    cin >> n;
    vector<vector<int>> caps;
    for(int i = 0; i < n; i++){
        // Read a line. Simmilar to map(int, input().split()) in python
        // Getline is used to read a line from the input
        // We get a line of integers separated by spaces
        string line;
        getline(cin, line);
        // We create a vector of integers
        vector<int> aux;
        // We map the integers to the vector
        for(int j = 0; j < line.size(); j++){
            if(line[j] != ' '){
                aux.push_back(line[j] - '0');
            }
        }
        // We add the vector to the vector of vectors
        caps.push_back(aux);
    }
    vector<vector<int>> result = bitmask(caps, n);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

