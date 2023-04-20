/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Time complexity: O(MxN), where M is the size of s and N is the size of t.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int numDistinct(string s, string t){
        int m = s.size();
        int n = t.size();
        vector<vector<unsigned int>> dp(m+1,vector<unsigned int>(n+1));

        // initialize the first row with 1s, as there is always a way to get an empty subsequence from s.
        for(auto i(0); i <= m; ++i){
            dp[i][0] = 1;
        }
        for(auto i(1); i <= m; ++i){
            for(auto j(1); j <= n; ++j){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    string s = "rabbbit";
    string t = "rabbit";
    cout << Solution::numDistinct(s,t) << "\n";
    return 0;
}