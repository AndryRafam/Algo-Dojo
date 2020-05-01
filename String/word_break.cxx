// Word break in O(N²) complexity


#include <bits/stdc++.h>
using namespace std;

bool LCS(string &a, string &b){
    int m = a.size();
    int n = b.size();
    int dp[m+1][n+1];
    for(auto i = 0; i <= m; i++){
        for(auto j = 0; j <= n; j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    string s = "lintcode";
    vector<string> dict = {"lint", "code"};
    for(auto x = 0; x < dict.size(); x++){
        string res = dict[x];
        for(auto y = x+1; y < dict.size(); y++){
            res+=dict[y];
            if(LCS(s,dict[x])&&LCS(s,dict[y])&&res.length()==s.length()){
                cout << "True";
                return 0;
            }
        }
    }
    cout << "False";
    return 0;
}
