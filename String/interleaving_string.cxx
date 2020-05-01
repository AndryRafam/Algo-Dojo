/* Interleaving string using LCS - O(M*N) complexity*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool LCS(string &a, string &b){
		int m = a.length();
		int n = b.length();
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
		if(dp[m][n]==b.size())
			return true;
		return false;
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	int m = s1.length();
	int n = s2.length();
	int p = s3.length();
	if(Solution::LCS(s3,s1)&&Solution::LCS(s3,s2)&&p==m+n) // True
		cout << "True";
	else
		cout << "False";
	return 0;
}
