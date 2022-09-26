#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
    sort(grid[0].begin(),grid[0].end());
    for (int i = 1; i < grid.size(); i++){
        sort(grid[i].begin(),grid[i].end());
        if(grid[i]<grid[i-1])return"NO";
    }
    return"YES";
}

int main()
{
    string filename("output.txt");
    fstream file_out;

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(t_temp);

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(n_temp);


        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);
            grid[i] = grid_item;
        }

        cout << "Processing...\n";

        string result = gridChallenge(grid);

        //Save the result to a file
        cout << result << "\n";

        file_out.open(filename, ios::out | ios::app);
        file_out << result << "\n";
        file_out.close();
    }

    //fout.close();

    return 0;
}
