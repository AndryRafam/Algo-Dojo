/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands. An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
Return the area of the largest island in matrix.
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &matrix, int i, int j){
    int m = matrix.size();
    int n = matrix[0].size();
    if(i < 0 or i >= m or j < 0 or j >= n or matrix[i][j]==0){
        return 0;
    }
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    int area = 0;
    if(matrix[i][j]==1){
        matrix[i][j]=0;
        for(auto k(0); k < 4; ++k){
            int newx = i+dx[k];
            int newy = j+dy[k];
            area+=dfs(matrix,newx,newy);
        }
    }
    return 1+area;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<int>> matrix = {
        {0,0,0,1,1,1,1},
        {0,0,0,0,0,0,0},
        {0,1,1,1,1,1,0},
        {0,0,1,1,0,0,0},
        {0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0}
    };
    int max_area = 0;
    for(auto i(0); i < matrix.size(); ++i){
        for(auto j(0); j < matrix[0].size(); ++j){
            max_area = max(max_area,dfs(matrix,i,j));
        }
    }
    cout << max_area << endl; // 7
    return 0;
}