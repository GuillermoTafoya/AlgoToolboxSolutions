#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int location, int dist, int tank, vector<int> & stops) {
    if (location + tank >= dist) {
        return 0;
    }
    if (stops.size() == 0 || (stops[0] - location) > tank) {
        return INT_MAX;
    }

    
    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(0, d, m, stops) << "\n";

    return 0;
}
