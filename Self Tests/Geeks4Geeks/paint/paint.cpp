//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        vector<pair<int,int>> queue;
        queue.push_back({sr, sc});
        int r,c,targetColor = image[sr][sc];
        while (queue.size()){
            tie(r,c) = queue.back(); 
            queue.pop_back();
            if (visited[r][c]){
                continue;
            }
            visited[r][c] = true;
            image[r][c]= newColor;
            searchNeighbours(image, queue, r, c, targetColor);
        }
        return image;
    }
    void searchNeighbours(vector<vector<int>>& image, vector<pair<int,int>> &queue, int r, int c, int targetColor){
        if (r > 0 && image[r-1][c] == targetColor){
            queue.push_back({r-1, c});
        }
        if (r < image.size()-1 && image[r+1][c] == targetColor){
            queue.push_back({r+1, c});
        }
        if (c > 0 && image[r][c-1] == targetColor){
            queue.push_back({r, c-1});
        }
        if (c < image[0].size()-1 && image[r][c+1] == targetColor){
            queue.push_back({r, c+1});
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        std::cout << "ans:\n";
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends