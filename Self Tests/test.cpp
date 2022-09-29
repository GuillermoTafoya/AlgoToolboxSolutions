#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'minNum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER threshold
 *  2. INTEGER_ARRAY points
 */

int search(vector<int> points, int target){
    // Search for the point that is exactly equal to the target or the point that is just bigger than the target.
    // As it is sorted, use binary search.
    int left = 0;
    int right = points.size() - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (points[mid] == target){
            return mid;
        }
        else if (points[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return left;
}

int minNum(int threshold, vector<int> points) {
    // Divide the problem in 3 parts:
    // 1. Binary search the difference for the treshold.
    // !! Meets or exceeds
    // 2. If not found, return N.
    // 3. If found, greedy aproach untill reaching the index of the difference.
    // You can skip one or two steps at a time.
    
    
    int min = points[0];
    int max = points[points.size()-1]-min;
    if (max < threshold){
        return points.size();
    }
    int target = min + threshold;
    int index = search(points,target);
    int sum = index / 2 + index % 2 + 1;
    for (int P:points){
        cout << P << ' ';
    }
    return sum;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    string points_count_temp;
    getline(cin, points_count_temp);

    int points_count = stoi(ltrim(rtrim(points_count_temp)));

    vector<int> points(points_count);

    for (int i = 0; i < points_count; i++) {
        string points_item_temp;
        getline(cin, points_item_temp);

        int points_item = stoi(ltrim(rtrim(points_item_temp)));

        points[i] = points_item;
    }

    int result = minNum(threshold, points);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}