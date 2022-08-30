//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    string findLongestWord(string S, vector<string> d) {
        sort(d.begin(),d.end(), [](std::string& a, std::string& b) {
        return (a.length() == b.length()) ? (a < b) : (a.length() > b.length());
    });
        for (int i = 0; i < d.size(); i++){
            
            if (isPossible(S,d[i])){
                return d[i];
            }
        }
        return "";
    }
    
    bool isPossible(string inputString, string target){
        int nowLookingAt = 0;
        int currentTarget = 0;
        while (nowLookingAt < inputString.length()){
            if (target[currentTarget] == inputString[nowLookingAt]){
                currentTarget++;
            }
            if (currentTarget == target.length()){
                return true;
            }
            nowLookingAt++;
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> d(n + 1);
        for (int i = 0; i < n; i++) cin >> d[i];
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findLongestWord(S, d) << endl;
    }
    return 0;
}

// } Driver Code Ends