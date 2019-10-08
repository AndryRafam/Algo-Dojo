/* Climb stairs - O(N) time complexity && O(N) space complexity*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int climbStairs(int n){
        if(n==1)
            return 1;
        int dp[n+1];
        dp[1]=1;
        dp[2]=2;
        for(auto i = 3; i <= n; ++i)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    int n = 4;
    cout << Solution::climbStairs(n);
}
