//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        if (n == 1){
            if (arr[0] == s){
                return {1,1};
            }
            return {-1};
        }
        int left = 0;
        int right = 0;
        long long runningSum = arr[left];
        while ((right < n ) && (left <= right)){
            
            if (runningSum < s){
                right++;
                runningSum += arr[right];
            }
            else if (runningSum > s) {
                if (left != right){
                    runningSum -= arr[left];
                    left++;
                }else{
                    right++;
                    runningSum += arr[right];
                }
            }
            else{
                return {left+1,right+1};
            }
        }
        
        if (runningSum == s){
            return {left+1,right+1};
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends