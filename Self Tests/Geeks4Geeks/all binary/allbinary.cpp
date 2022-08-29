//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		vector<string> generate_binary_string(string &s)
		{
		    vector<string> solution;
		    for (auto &ch : s){
		        if (ch == '?'){
		            if (solution.size()){
		                int n = solution.size();
		                for (int i = 0; i < n; i++){
		                solution.push_back(solution[i] + "0");
		                solution[i] += "1";
		                
		                }
		            }
		            else{
		                solution.push_back("1");
		                solution.push_back("0");
		                
		            }
		        }
		        else{
		            if (solution.size()){
		                for (int i = 0; i < solution.size(); i++){
		                solution[i] += ch;
		                }
		            }
		            else{
		                string str1(1, ch);
		                solution.push_back(str1);
		            }
		            
		        }
		    }
		    sort(solution.begin(),solution.end());
		    return solution;
		}
		
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends