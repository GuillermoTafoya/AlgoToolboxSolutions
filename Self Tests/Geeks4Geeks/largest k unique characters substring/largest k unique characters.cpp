//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        if (s.size() == 1){
            return k==1 ? 1 : -1;
        }
    map<char,int> currentUniqueCharacters;
    int currentUniqueCharactersCount = 0;
    int left = 0, right = 0, maxSubstring = -1, currentSubstring = 0;
    for (right; right<s.size(); right++){
        // If the character we are looking for is already taken into account
        if (currentUniqueCharacters[s[right]]) {
            currentUniqueCharacters[s[right]]++;
            currentSubstring++;
            if (currentUniqueCharactersCount == k){
                maxSubstring = max(maxSubstring, currentSubstring);
            }
        } else{ // It is a new character
            currentUniqueCharacters[s[right]]++;
            currentUniqueCharactersCount++;
            currentSubstring++;
            // While the currentUniqueCharactersCount is greater than K
            // We move the running window to meet the requirements
            while (currentUniqueCharactersCount > k){
                currentUniqueCharacters[s[left]]--;
                currentSubstring--;
                // If we already eliminated a unique character, substract one to the counter
                if (!currentUniqueCharacters[s[left]]){
                    currentUniqueCharactersCount--;
                }
                left++;
                
            }
            if (currentUniqueCharactersCount == k){
                maxSubstring = max(maxSubstring, currentSubstring);
            }
        }
    }
    return maxSubstring;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends