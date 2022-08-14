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
    // If the past filter is not enough to reach the destination, check if the current filter is enough to reach the destination.
    // If the stops is empty, given that the distance is not reachable, it is impossible to reach the destination.
    // Also, if the next stop is not reachable, it is impossible to reach the destination.
    if (stops.size() == 0 || (stops[0] - location) > tank) {
        return INT_MAX;
    }
    int last_refill = location;
    // Look for the furthest reachable stop.
    while (stops.size() > 0 && (stops[0] - last_refill) <= tank) {
        last_refill = stops[0];
        stops.erase(stops.begin());
    }
    // Recursive call to compute the minimum number of refills.
    return 1 + compute_min_refills(last_refill, dist, tank, stops);
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
