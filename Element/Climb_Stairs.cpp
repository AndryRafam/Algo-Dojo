/* You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int climbStairs(int n){
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(auto i = 1; i <= n; ++i)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    int n = 12;
    cout << Solution::climbStairs(n); // 233
}
