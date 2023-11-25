/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
 * which minimizes the sum of all numbers along its path.
 * You can only move either down or right at any point in time.
 * 
 * Time complexity: O(M*N), where M is the number of lines and N is the number of columns.
*/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> grid){
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m,vector<int>(n,0));
	dp[0][0]=grid[0][0];
	// fill the 1st row
	for(size_t j = 1; j < m; ++j){
		dp[0][j]=dp[0][j-1]+grid[0][j];
	}
	// fill the 1st column
	for(size_t i = 1; i < n; ++i){
		dp[i][0]=dp[i-1][0]+grid[i][0];
	}
	for(size_t i = 1; i < m; ++i){
		for(size_t j = 1; j < n; ++j){
			dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m-1][n-1];
}

int main(){
	ios_base::sync_with_stdio(false);
	vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
	cout << minPathSum(grid);
	return 0;
}
