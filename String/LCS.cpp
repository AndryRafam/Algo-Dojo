// Longest common subsequence

#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, string s3){
    int m = s1.length();
    int n = s2.length();
    int o = s3.length();
    int dp[m+1][n+1][o+1];
    for(auto i = 0; i < m; ++i){
        for(auto j = 0; j < n; ++j){
            for(auto k = 0; k < o; ++k){
                if(i==0||j==0||k==0){
                    dp[i+1][j+1][k+1]=0;
                }
                else if(s1[i]==s2[j]&&s1[i]==s3[k]){
                    dp[i+1][j+1][k+1]=dp[i][j][k]+1;
                }
                else{
                    dp[i+1][j+1][k+1]=max({dp[i][j+1][k+1],dp[i+1][j][k+1],dp[i+1][j+1][k]});
                }
            }
        }
    }
    return dp[m][n][o];
}

int main(){
    ios_base::sync_with_stdio(false);
    string s1 = "GeekforGeek";
    string s2 = "Geek";
    string s3 = "Aggtgek";
    cout << LCS(s1,s2,s3) << "\n";
    return 0;
}
