// Longest common subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        static int LCS(string &s1, string &s2, string &s3){
            int m = s1.length();
            int n = s2.length();
            int o = s3.length();
            int L[m+1][n+1][o+1];

            for(auto i = 0; i <= m; ++i){
                for(auto j = 0; j <= n; ++j){
                    for(auto k = 0; k <= o; ++k){
                        if(i==0 || j==0 || k==0)
                            L[i][j][k] = 0;
                        else if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1])
                            L[i][j][k] = L[i-1][j-1][k-1]+1;
                        else
                            L[i][j][k] = max({L[i-1][j][k],L[i][j-1][k],L[i][j][k-1]});
                    }
                }
            }
            return L[m][n][o];
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    string s1 = "GeekforGeek";
    string s2 = "Geek";
    string s3 = "Aggtgek";
    cout << Solution::LCS(s1,s2,s3);
    return 0;
}
