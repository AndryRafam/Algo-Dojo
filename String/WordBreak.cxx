// Word breaking O(N³) time complexity (Dynamic programming)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    public:
    static bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.length();
        unordered_set<string> wordSet({wordDict.begin(),wordDict.end()});
        vector<bool> dp(n+1);
        dp[0]=true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && wordSet.count(s.substr(j,i-j))) {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

auto main()->int {
    ios::sync_with_stdio(false);
    string s = "catsandog";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    cout << (Solution::wordBreak(s,wordDict)==1 ? "true":"false");
    return 0;
}
