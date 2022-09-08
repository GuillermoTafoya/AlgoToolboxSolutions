#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
long long solution(vector<int> x, vector<int> y) {
vector<vector<bool>> cartesianPlane(2000, vector<bool>(2000,false));
int y_coord, x_coord, y_coord_prime, x_coord_prime;
// Init Cartesian plane
for (int i = 0; i < x.size(); i++){
    tie(y_coord,x_coord) = {y[i],x[i]};
    y_coord += 999;
    x_coord += 999;
    x[i] = x_coord;
    y[i] = y_coord;
    cartesianPlane[y_coord][x_coord] = true;
}
long long squares = 0;
int size = cartesianPlane.size();
int dif;

for (int i = 0; i < x.size(); i++){
    tie(y_coord,x_coord) = {y[i],x[i]};
    cout << "x_coord: " << x_coord << " y_coord: " << y_coord << '\n';
    // Track row & col
    for (int i_prime = x_coord+1; i < size; i++){
        // Axis aligned squares
        if (cartesianPlane[y_coord][i]){
            dif = i_prime-x_coord;
            // Calculate if out of bounds
            if(y_coord+dif>=size){
                continue;
            }
            // Calculate four points
            if (cartesianPlane[y_coord+dif][x_coord] && cartesianPlane[y_coord+dif][i]){
                squares++;
                cout << "points: (" << x_coord-999 << "," << y_coord-999 << ") (" << i-999 << "," << y_coord-999 << ") (" << x_coord-999 << "," << y_coord+dif-999 << ") (" << i-999 << "," << y_coord+dif-999 << ")" << '\n';
            }
        }
    }
    // Diagonal squares
    vector<bool> visited (size,false);
    for (int j = i+1; j < size; j++){
        tie(y_coord_prime,x_coord_prime) = {y[j],x[j]};
        if (visited[y_coord_prime][x_coord_prime]){
            continue;
        }
        visited[y_coord_prime][x_coord_prime] = true;
        int differenceInX, differenceInY;
        differenceInX = abs(x_coord_prime-x_coord);
        differenceInY = abs(y_coord_prime-y_coord);
        if (cartesianPlane[y_coord-differenceInX][x_coord-differenceInY] && cartesianPlane[y_coord_prime-differenceInX][x_coord_prime-differenceInY]){
            squares++;
            cout << "points: (" << x_coord-999 << "," << y_coord-999 << ") (" << x_coord_prime-999 << "," << y_coord_prime-999 << ") (" << x_coord-differenceInX-999 << "," << y_coord-differenceInX-999 << ") (" << x_coord+differenceInX-999 << "," << y_coord+differenceInX-999 << ")" << '\n';
        }


    }

    // print the matrix, but only between the limits of the points
    int leftLimit = *min_element(x.begin(),x.end());
    int rightLimit = *max_element(x.begin(),x.end());
    int bottomLimit = *min_element(y.begin(),y.end());
    int  topLimit = *max_element(y.begin(),y.end());
    for (int i = bottomLimit; i <= topLimit; i++){
        for (int j = leftLimit; j <= rightLimit; j++){
            cout << cartesianPlane[i][j] << " ";
        }
        cout << '\n';
    }
}
    return squares;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    long long result = solution(x, y);
    cout << "Result: " << result << endl;
    return 0;
}
/*
Input:
7
-1 -1 -1 0 0 0 1
-1 0 1 -1 0 1 0
Expected Output:
3
*/