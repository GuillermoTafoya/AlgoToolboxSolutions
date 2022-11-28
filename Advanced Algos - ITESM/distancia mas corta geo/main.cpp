#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


struct Point{
    float x;
    float y;
};

float distance(Point p1, Point p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

float minDistance(vector<Point> points, int n){
    float min = distance(points[0], points[1]);
    for(int i = 0; i < n; i++){ 
        for(int j = i + 1; j < n; j++){
            float dist = distance(points[i], points[j]);
            if(dist < min){
                min = dist;
            }
        }
    }
    // O(n^2)
    return min;
}

int main(){
    int n;
    cin >> n;
    vector<Point> points;
    for(int i = 0; i < n; i++){
        Point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }
    cout << "La distancia mas corta es: " << minDistance(points, n) << endl;
    return 0;
}