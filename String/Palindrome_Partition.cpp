// Find all partition palindrome of a given string

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        static bool palindrome(string &s){
            int n = s.length();
            for(auto i = 0; i < n/2; ++i){
                if(s[i]!= s[n-1-i])
                    return false;
            }
            return true;
        }
        static void palindrome_substr(string &s){
            string temp = "";
            for(auto i = 0; i < s.length(); ++i){
                for(auto len = 1; len <= s.length()-i; ++len){
                    temp = s.substr(i,len);
                    if(palindrome(temp))
                        cout << temp << " ";
                    else
                        continue;
                }
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    string test = "aab";
    Solution::palindrome_substr(test);
}
