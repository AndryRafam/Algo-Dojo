/*
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions is allowed Up, Down, Right, Left.
*/ 

#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:
	static bool dfs(vector<vector<int>> &maze, int x, int y){
		int N = maze.size();
		int M = maze[0].size();
		vector<int> row = {-1,0,0,1};
		vector<int> col = {0,-1,1,0};
		if(x<0 || x>=N || y<0 || y>=M || maze[x][y]!=1){
			return false;
		}
		if(x==N-1 && y==M-1){
			return true;
		}
		else if(maze[x][y]==1){
			maze[x][y]='$';
			for(int k(0); k < 4; ++k){
				if(dfs(maze,x+row[k],y+col[k])){
					return true;
				}
			}
		}
		return false;
	}
	static bool path(vector<vector<int>> &maze){
		if(!dfs(maze,0,0)){
			return false;
		}
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	vector<vector<int>> maze = {{1, 0, 0, 1, 1, 1},
				    {1, 1, 0, 1, 0, 1},
				    {0, 1, 1, 1, 0, 1},
				    {0, 0, 1, 0, 1, 1},
				    {0, 0, 1, 0, 1, 0},
				    {0, 0, 1, 0, 1, 1}}; // True in this example
								
	cout << (Solution::path(maze)==1 ? "True":"False") << endl;
	return 0;
}
