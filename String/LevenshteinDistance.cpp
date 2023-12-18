/*Levenshtein Distance*/

#include <bits/stdc++.h>
using namespace std;

int levenshteinDistance(const string &s1, const string &s2) {
	int m = s1.length();
	int n = s2.length();
	int cost;
	int dp[m+1][n+1];
	for(int i = 0; i <= m; ++i) {
		dp[i][0]=i;
	}
	for(int j = 0; j <= n; ++j) {
		dp[0][j]=j;
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cost = (s1[i-1]==s2[j-1]) ? 0:1;
			dp[i][j]=min({dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+cost});
		}
	}
	return dp[m][n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	string t; cin >> t;
	cout << levenshteinDistance(s,t);
	return 0;
}
