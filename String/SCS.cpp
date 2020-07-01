// Shortest Common Supersequence

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int LCS(string &X, string &Y){
		int m = X.length();
		int n = Y.length();
		int dp[m+1][n+1];
		for(auto i = 0; i <= m; i++){
			for(auto j = 0; j <= n; j++){
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(X[i-1]==Y[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
			}
		}
		return dp[m][n];
		
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	string X = "ABCBDAB";
	string Y = "BDCABA";
	int m = X.length();
	int n = Y.length();
	cout << m+n-Solution::LCS(X,Y) << endl;
	return 0;
}
