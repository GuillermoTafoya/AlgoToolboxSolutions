/*
Write a C++ program that implements the algorithm to determine the smallest
convex polygon in a set of points by applying the Incremental algorithm.

The program receives a set of n points located on a Cartesian plane.
The output of the program will be an array of points (vertices) in 
counterclockwise order that define the convex polygon. 

The array should be output to standard output.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

// Returns the orientation of the three points
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// Prints convex hull of a set of n points.
vector<Point> convexHull(Point points[], int n) {
    // There must be at least 3 points
    if (n < 3) return vector<Point>();

    // Initialize Result
    vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%n;
        for (int i = 0; i < n; i++) {
            // If i is more counterclockwise than current q, then
            // update q
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    } while (p != l);  // While we don't come to first point

    return hull;
}

void randomPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
}

void printPoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "(" << points[i].x << ", " << points[i].y << ") ";
    }
    cout << endl;
}

void printHull(vector<Point> hull) {
    for (int i = 0; i < hull.size(); i++) {
        cout << "(" << hull[i].x << ", " << hull[i].y << ") ";
    }
    cout << endl;
}

/*
//Random points
int main() {
    int n = 10;
    Point points[n];
    randomPoints(points, n);
    printPoints(points, n);
    vector<Point> hull = convexHull(points, n);
    printHull(hull);
    return 0;
}
*/

//Given points
int main() {
    int n; // number of points
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<Point> hull = convexHull(points, n);
    printHull(hull);
    return 0;
}