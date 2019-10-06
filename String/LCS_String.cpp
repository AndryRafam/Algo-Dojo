// Longest common substring

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        static int lcs_string(string &s1, string &s2, string &s3){
            int m = s1.length();
            int n = s2.length();
            int o = s3.length();
            int result = 0;
            int L[m+1][n+1][o+1];

            for(auto i = 0; i <= m; ++i){
                for(auto j = 0; j <= n; ++j){
                    for(auto k = 0; k <= o; ++k){
                        if(i==0 || j==0 || k==0)
                            L[i][j][k] = 0;
                        else if(s1[i-1]==s2[j-1] && s1[i-1]==s3[k-1]){
                            L[i][j][k] = L[i-1][j-1][k-1]+1;
                            result = max(result,L[i][j][k]);
                        }
                    }
                }
            }
            return result;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    string s1 = "OldGame: Assassin's Creed";
    string s2 = "NewGame: Assassin's Creed 3";
    string s3 = "LastGame: Assassin's Creed Odyssey";
    cout << Solution::lcs_string(s1,s2,s3);
    return 0;
}
