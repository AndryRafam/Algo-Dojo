#include <bits/stdc++.h>
using namespace std;

bool SS(string &X, string &Y){
    int m = X.length();
    int n = Y.length();
    int dp[m+1][n+1];
    for(auto i = 0; i <= m; ++i){
        for(auto j = 0; j <= n; ++j){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(X[i-1]==Y[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string X = "vghifagfhjajeidhedgdgciacccjidhhvdfeebvbavvehdabgh";
    string Y = "gcyecbhgydwizvygceibfiaezwjazdvggivjjcaigxcgiayvehwvbxaajjbixwzeevyzyzhewjwfvjazbwvdjvddeexcbxhfhgef";
    if(SS(X,Y)!=0)
        cout << "OK";
    else
        cout << "NOK";
}
