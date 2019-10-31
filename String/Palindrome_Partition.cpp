// Find all palindrome partition of given string

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
        static vector<string> palindrome_substr(string &s){
            string temp = "";
            vector<string> res;
            for(auto i = 0; i < s.length(); ++i){
                for(auto len = 1; len <= s.length()-i; ++len){
                    temp = s.substr(i,len);
                    if(palindrome(temp))
                        res.emplace_back(temp);
                }
            }
            return res;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    string test = "aab";
    for(auto &x : Solution::palindrome_substr(test))
        cout << x << " ";
}
