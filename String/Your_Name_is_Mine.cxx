/*
Problem

In an attempt to control the rise in population, Archer was asked to come up with a plan. This time he is targeting marriages. 
Archer, being as intelligent as he is, came up with the following plan:
A man with name M is allowed to marry a woman with name W, only if M is a subsequence of W or W is a subsequence of M.
A is said to be a subsequence of B, if A can be obtained by deleting some elements of B without changing the order 
of the remaining elements.
Your task is to determine whether a couple is allowed to marry or not, according to Archer's rule.

Input

The first line contains an integer T, the number of test cases. T test cases follow. Each test case contains two space separated 
strings M and W.

Output

For each test case print "YES" if they are allowed to marry, else print "NO". (quotes are meant for clarity, 
please don't print them)

Time complexity: O(N*M), where N is the length of s and M is the length of w. We are using LCS (Longest Common Subsequence)
algorithm here.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static int allow_marry(string a, string b) {
		int n = a.length();
		int m = b.length();
		vector<vector<int>> dp(n+1,vector<int> (m+1));

		for(auto i(0); i <= n; ++i) {
			for(auto j(0); j <= m; ++j) {
				if(i==0 || j==0) {
					dp[i][j]=0;
				}
				else if(a[i-1]==b[j-1]) {
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else {
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		return dp[n][m];
	}
};

int main (int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	string s, w;
	int t;
	cin >> t;
	for (auto x(0); x < t; ++x) {
		cin >> s >> w;
		//if len LCS(s,w) is equal to s or to w, then the couple are allowed to marry.
		if(Solution::allow_marry(s,w)==s.length() || Solution::allow_marry(s,w)==w.length()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}