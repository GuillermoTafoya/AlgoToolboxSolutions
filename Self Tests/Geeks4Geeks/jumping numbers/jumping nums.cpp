// { Driver Code Starts

#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

 // } Driver Code Ends


class Solution {
    public:
    long long jumpingNums(long long X) {
        if (X<10){
            return X;
        }
        int firstDigit, secondDigit;
        tie(firstDigit, secondDigit) = getFurthestLeftIntegers(X);
        if (firstDigit - secondDigit < 2){
            return firstCase(X,1,X).first;
        }
        X = X -  pow(10,getNumDigits(X)-1);
        return secondCase(X,1,X).first;
    }
    int getNumDigits(long long X){
        int numDigits = 0;
        while (X>0){
            numDigits++;
            X/=10;
        }
        return numDigits;
    }
    pair<long long, int> firstCase(long long X, long long exponent, long long limit){
        //cout << "First Case: " << X << '\n';
        if (X<10){
            return {X*exponent,X};
        }
        
        long long  prevDigits;
        int lastDigit, currentDigit;
        currentDigit = X%10;
        tie(prevDigits, lastDigit)= firstCase(X/10,exponent*10,limit);
        //cout << "First Recursion: " << prevDigits << '\n';
        if (lastDigit - currentDigit > 1){
            prevDigits = prevDigits - pow(10,getNumDigits(prevDigits)-3) - lastDigit*exponent;
            return secondCase(prevDigits,1,limit);
        }
        int newDigit = (lastDigit != 9 && prevDigits+((lastDigit+1)*exponent) <= limit) ? lastDigit+1 : lastDigit-1;
        long long newDigits = prevDigits+newDigit*exponent;
        return {newDigits, newDigit};
        
    }
    pair<long long, int> secondCase(long long X, long long exponent, long long limit){
        //cout << "Second Case: " << X << '\n';
        if (X<10){
            return {X*exponent,X};
        }
        long long  prevDigits;
        int lastDigit;
        tie(prevDigits, lastDigit)= secondCase(X/10,exponent*10,limit);
        //cout << "Second Recursion: " << prevDigits << '\n';
        int newDigit = (lastDigit != 9 && prevDigits+((lastDigit+1)*exponent) <= limit) ? lastDigit+1 : lastDigit-1;
        long long newDigits = prevDigits+newDigit*exponent;
        return {newDigits, newDigit};
        
    }
    pair<int,int> getFurthestLeftIntegers(long long X){
        int a,b;
        a = X % 10;
        X = X / 10;
        while (X>10){
            a = X % 10;
            X = X / 10;
        }
        return {X,a};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}  // } Driver Code Ends