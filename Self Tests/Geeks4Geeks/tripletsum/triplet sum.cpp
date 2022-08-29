#include <iostream>
#include <algorithm>
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        std::sort(arr,arr+n);
        for (int i = 0; i < n-1; i++){
            int l = i + 1;
            int r = n - 1;
            int x = arr[i];
            while (l < r){
                int sum = x + arr[l] + arr[r];
                if (sum == 0){
                    return true;
                }
                if (sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return false;
    }
};