#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static long long int max_len(string &s1, string &s2){
        if(s1.length()!=s2.length())
            return -1;
        int N = s1.length();
        long long int result = 0;
        long long int dp[N+1][N+1];
        for(auto i = 0; i <= N; ++i){
            for(auto j = 0; j <= N; ++j){
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    result = max(result,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        return result;
    }
};
int main(){
    string s1 = "rcrccrcrcccrrccrrccc";
    string s2 = "rcccrccrcccrcrcccrrc";
    printf("%lld",Solution::max_len(s1,s2));
}
