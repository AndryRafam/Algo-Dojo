/*BattleDev: Tech Challenger - Session 10 Janvier.

Tech Challengers - Qualif 3 - 2*/

#include <bits/stdc++.h>
using namespace std;

void LCS(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(auto i(0); i <= m; ++i){
        dp[i][0]=0;
    }
    for(auto j(0); j <= n; ++j){
        dp[0][j]=0;
    }
    for(auto i(1); i <= m; ++i){
        for(auto j(1); j <= n; ++j){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if(dp[m][n]==0){
        cout << "NORMAL";
        return;
    }
    stack<char> st;
    int i = m; int j = n;
    while(i > 0 and j > 0){
        if(s1[i-1]==s2[j-1]){
            st.push(s1[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    string lcs = "";
    while(!st.empty()){
        lcs+=st.top();
        st.pop();
    }
    cout << "TEMPÊTE" << endl;
    cout << lcs << endl;
    return;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    LCS(s1,s2);
    return 0;
}