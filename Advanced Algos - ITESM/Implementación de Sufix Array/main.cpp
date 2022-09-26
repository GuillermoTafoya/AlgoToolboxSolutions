// Given a string S, find the different substrings of S and return them in alphabetical order.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> substrings;
    for (int i = 0; i < s.size(); i++) {
        substrings.push_back(s.substr(i));
    }
    sort(substrings.begin(), substrings.end());
    for (int i = 0; i < substrings.size(); i++) {
        cout << substrings[i] << endl;
    }
    return 0;
}