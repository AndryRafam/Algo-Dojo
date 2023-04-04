/* Climb stairs with at most k steps. (k > 0)
 * Time complexity: O(n*k), where n is the number of staircases and k is the maximum step allowed.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int  climbStairs_k(int n, int k){
		vector<int> dp(n+1,0);
		dp[0] = 1;
		for(auto i(1); i <= n; ++i){
			for(auto j(1); j <= k; ++j){
				if (i-j >= 0){
					dp[i] += dp[i-j];
				}
			}
		}
		return dp[n];
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	int n = 12;
	int k = 5;
	cout << Solution::climbStairs_k(n,k); // 1793
	return 0;
}
