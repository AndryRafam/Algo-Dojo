/* Maze problem: Starting from any point of the maze, find a way to the bottom right corner.
 * 
 * All directions is allowed Up, Down, Right, Left */ 

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool dfs(vector<vector<int>> &maze, int i, int j){
		int N = maze.size();
		int M = maze[0].size();
		if(i<0 || i>=N || j<0 || j>=M || maze[i][j]!=1)
			return false;
		if(i==N-1 && j==M-1)
			return true;
		if(maze[i][j]==1){
			maze[i][j]='$'; // mark cell as visited, so we can't visit it anymore
			if(dfs(maze,i+1,j) || dfs(maze,i,j+1) || dfs(maze,i-1,j) || dfs(maze,i,j-1)){ // four directions
				return true;
			}
			return false;
		}
		return false;
	}
	static bool path(vector<vector<int>> &maze, int x, int y){
		if(!dfs(maze,x,y))
			return false;
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<int>> maze = {{1, 0, 0, 0, 0, 0},
				    {1, 1, 0, 1, 1, 1},
				    {0, 1, 1, 1, 0, 1},
				    {0, 0, 1, 0, 1, 1},
				    {0, 1, 0, 1, 1, 0},
				    {0, 1, 1, 1, 1, 1}}; // True in this example
								
	cout << (Solution::path(maze,1,0)==1 ? "True":"False") << endl; // Start from second line, first column
	return 0;
}
