//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector <int> sol;
        map <int,int> visited;
        for (int i = 0; i < nums.size(); i++){
            visited[nums[i]]++;
        }
        for(auto &i : visited){
            if (i.second == 1){
                    sol.push_back(i.first);
                }
        }
    if (sol[0]<sol[1]){
        return {sol[0],sol[1]};
    }
    return {sol[1],sol[0]};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends