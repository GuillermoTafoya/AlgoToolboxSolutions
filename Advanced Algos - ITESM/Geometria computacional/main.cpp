// Given two set of points, find if their lines intersect
// input format:
// x1,y1,x2,y2,x3,y3,x4,y4
// output format:
// true if lines intersect, false otherwise

#include <iostream>

using namespace std;

bool isIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int a1 = y2 - y1;
    int b1 = x1 - x2;
    int c1 = a1 * x1 + b1 * y1;
    int a2 = y4 - y3;
    int b2 = x3 - x4;
    int c2 = a2 * x3 + b2 * y3;
    int determinant = a1 * b2 - a2 * b1;
    if (determinant == 0) {
        return false;
    } else {
        int x = (b2 * c1 - b1 * c2) / determinant;
        int y = (a1 * c2 - a2 * c1) / determinant;
        if (x >= min(x1, x2) && x <= max(x1, x2) && x >= min(x3, x4) && x <= max(x3, x4) && y >= min(y1, y2) && y <= max(y1, y2) && y >= min(y3, y4) && y <= max(y3, y4)) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int n; // n is a multiple of 4
    cin >> n;
    for (int i = 0; i < n; i += 4) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << isIntersect(x1, y1, x2, y2, x3, y3, x4, y4) << '\n';
    }
    return 0;
}