#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int DL(string &s1, string &s2){
        int m = s1.length();
        int n = s2.length();
        int dp[m+1][n+1];
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if (i==0)
                    dp[i][j]=j;
                else if (j==0)
                    dp[i][j]=i;
                else
                    dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(s1[i-1]==s2[j-1] ? 0:1)}); // Levenshtein classic
                if (i>0 && j>0 && s1[i]==s2[j-1] && s1[i-1]==s2[j])
                    dp[i][j]=1+min(dp[i][j],dp[i-2][j-2]); // Transposition
            }
        }
        return dp[m][n];
    }
};
int main(){
    string test1 = "pantera";
    string test2 = "aorta";
    printf("%d",Solution::DL(test1,test2));
}
