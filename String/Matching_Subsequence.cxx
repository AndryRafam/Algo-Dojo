/* Given string source and a dictionary of words words, return list of words[i] that is a subsequence of source.

O(K*M*N) complexity where K is the size of words array*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int LCS(string &s1, string &s2){
        int m = s1.length();
        int n = s2.length();
        int dp[m+1][n+1];
        for(auto i = 0; i <= m; ++i){
            for(auto j = 0; j <=n; ++j){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    string source = "bcogtadsjofisdhklasdej";
    vector<string> words = {"book","code","tag"};
    for(auto &x : words){
        if(Solution::LCS(source,x)==x.length())
            cout << x << " "; // book, code
    }
    return 0;
}
