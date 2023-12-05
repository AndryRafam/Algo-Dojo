/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that
the robot can take to reach the bottom-right corner.

Time complexity: O(M*N).
*/

#include <bits/stdc++.h>
using namespace std;

int uniquePath(int m, int n){
    vector<vector<int>> dp(m,vector<int>(n));
    for(auto i = 0; i < m; ++i){
        dp[i][0]=1;
    }
    for(auto j = 0; j < n; ++j){
        dp[0][j]=1;
    }
    for(auto i = 1; i < m; ++i){
        for(auto j = 1; j < n; ++j){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    int m = 3;
    int n = 7;
    cout << uniquePath(m,n);
    return 0;
}
