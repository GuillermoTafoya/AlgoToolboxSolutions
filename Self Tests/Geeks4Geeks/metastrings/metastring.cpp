//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string S1, string S2)
{
    pair<char,char> diff1,diff2;
    int current = 0;
    for (int i = 0; i < S1.size(); i++){
        if (S1[i] != S2[i]){
            current++;
            if (current > 2){
            return 0;
            }
            if (current == 1){
                diff1 = {S1[i],S2[i]};
                continue;
            }
            diff2 = {S2[i],S1[i]};
        }
    }
    if (current < 2){
        return 0;
    }
    return diff1 == diff2;
}