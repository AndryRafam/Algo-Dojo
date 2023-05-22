/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which maximizes the sum of all numbers along its path.
You can only move either down or right at any point in time.

Time complexity: O(M*N), where M is the number of lines and N is the number of columns.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int maxPathSum(vector<vector<int>> &arr){
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> sum(m,vector<int>(n,0));
        sum[0][0] = arr[0][0];
        // fill the 1st col
        for(auto i(1); i < m; ++i){
            sum[i][0] = arr[i][0]+sum[i-1][0];
        }
        // fill the 1st row
        for(auto j(1); j < n; ++j){
            sum[0][j] = arr[0][j]+sum[0][j-1];
        }
        for(auto i(1); i < m; ++i){
            for(auto j(1); j < n; ++j){
                sum[i][j] = max(sum[i-1][j],sum[i][j-1])+arr[i][j];
            }
        }
        return sum[m-1][n-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<int>> arr = {{1,3,1},{1,5,1},{4,2,1}};
    cout << Solution::maxPathSum(arr) << endl;
    return 0;
}
