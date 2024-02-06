/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. 
A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Time complexity: O(MxN); where MxN is the dimension of the 2D grid.
*/

#include <iostream>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false);

template <typename T>
T uniquePathsWithObstacles(vector<vector<T>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    
    for(int i = 0; i < m && obstacleGrid[i][0]==0; ++i) {
        dp[i][0]=1;
    }
    for(int j = 0; j < n && obstacleGrid[0][j]==0; ++j) {
        dp[0][j]=1;
    }

    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            if(obstacleGrid[i][j]==0) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(int argc, char **argv) {
    fast_io;
    cin.tie(0);
    vector<vector<int>> test = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles<int>(test);
    return 0;
}