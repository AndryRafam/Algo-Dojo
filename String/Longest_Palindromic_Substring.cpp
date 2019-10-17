// Longest palindromic substring - Brute force approach

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool compare(string &s1, string &s2){ // Function to compare the string length
        return s1.size() < s2.size();
    }
    static bool palindrome(string &s){
        int n = s.length();
        for(auto i = 0; i < n/2; ++i)
            if(s[i]!=s[n-1-i])
                return false;
        return true;
    }
    static void longest_palindrome(string &s){
        string temp = "";
        vector<string> str;
        for(auto i = 0; i < s.length(); ++i){
            for(auto j = 1; j <= s.length()-i; ++j){
                temp = s.substr(i,j);
                if(palindrome(temp))
                    str.emplace_back(temp);
            }
        }
        sort(str.begin(),str.end(), compare);
        cout << str[str.size()-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    string test = "xabax"; // result is "xabax"
    Solution::longest_palindrome(test);
}
