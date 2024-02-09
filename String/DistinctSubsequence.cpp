/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Time complexity: O(MxN), where M is the size of s and N is the size of t.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

class Solution{
    public:
    static int numDistinct(string s, string t){
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        // empty string is always a subsequence of any strings.
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
    fast_io;
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    cout << Solution::numDistinct(s,t) << "\n";
    return 0;
}
