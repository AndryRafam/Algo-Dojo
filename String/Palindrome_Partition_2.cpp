/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Dynamic programming approach.

Time complexity: O(N*2^N), where N is the length of the string S.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool> (len,false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }
    private:
    static void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if(start >= s.length()) {
            result.emplace_back(currentList);
        }
        for(auto end = start; end < s.length(); ++end) {
            if(s[start]==s[end] && (end-start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                currentList.emplace_back(s.substr(start,end-start+1));
                dfs(result,s,end+1,currentList,dp);
                currentList.pop_back();
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    string s = "aab";
    for(auto &x : Solution::partition(s)) {
        for(auto &y : x) {
            cout << y << " ";
        }
    }
    return 0;
}
