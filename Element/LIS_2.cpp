/*
Longest Increasing Subsequence in 2D grid.

Time Complexity: O(M*N), where M*N is the size of the grid.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    static int dfs(vector<vector<int>> grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int max_len = 0;
        vector<pair<int,int>> directions = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        for(auto &dir : directions){
            int x = i+dir.first;
            int y = j+dir.second;
            if(x >= 0 and x < m and y >= 0 and y < n and grid[x][y] > grid[i][j]){
                max_len = max(max_len,dfs(grid,x,y));
            }
        }
        dp[i][j] = max_len+1;
        return dp[i][j];
    }
    public:
    static int lis(vector<vector<int>> grid){
        int m = grid.size();
        int n = grid[0].size();
        int max_len = 0;
        for(auto i(0); i < m; ++i){
            for(auto j(0); j < n; ++j){
                max_len = max(max_len,dfs(grid,i,j));
            }
        }
        return max_len;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> grid = {{9,9,4},
                                {6,6,8},
                                {2,1,1}};
    cout << Solution::lis(grid) << "\n";
    return 0;
}
