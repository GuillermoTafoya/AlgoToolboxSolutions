#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(string s){
    string reversed = s;
    reverse(reversed.begin(),reversed.end());
    return s == reversed;
}

int palindromeIndex(string s) {
    if (isPalindrome(s))return-1;
    int size = s.size(), limit = size%2==0?size/2-1:size/2;
    for(int i = 0; i < limit; i++){
        if (s[i]!=s[size-i-1]){
            string test = s.substr(0,i)+s.substr(i+1);
            if (isPalindrome(test))return i;
            test = s.substr(0,size-i-1)+s.substr(size-i);
            if (isPalindrome(test))return size-i-1;
            return -1;
        }
    }
    return -1;
}
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}