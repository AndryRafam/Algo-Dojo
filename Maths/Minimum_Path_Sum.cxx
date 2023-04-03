/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
 * which minimizes the sum of all numbers along its path.
 * You can only move either down or right at any point in time.
 * 
 * Time complexity: O(M*N), where M is the number of lines and N is the number of columns.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int minPathSum(vector<vector<int>> &grid){
		int M = grid.size();
		int N = grid[0].size();
		vector<vector<int>> dp(M, vector<int> (N,0));
		dp[0][0] = grid[0][0];
		
		//fill the 1st row
		for(int j(1); j < M; ++j){
			dp[0][j] = dp[0][j-1]+grid[0][j];
		}
		//fill the 1st column
		for(int i(1); i < N; ++i){
			dp[i][0] = dp[i][0]+grid[i][0];
		}
		for(int i(1); i < M; ++i){
			for(int j(1); j < N; ++j){
				dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
			}
		}
		return dp[M-1][N-1];
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	vector<vector<int>> grid = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
	cout << Solution::minPathSum(grid);
	return 0;
}
