/*
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions are allowed Up, Down, Right, Left.
Print the solution if there is one, otherwise, print NO PATH.
*/

#include <bits/stdc++.h>
using namespace std;

#define Yellow "\x1B[33m"
#define Reset "\x1B[0m"

class Solution {
	public:
	static bool path(vector<vector<int>> &maze,int x, int y, int tx, int ty){
		vector<vector<int>> sol(maze);
		if(dfs(maze,x,y,tx,ty,sol)){
			printPath(sol);
			return true;
		}
		cout << "NO PATHS";
		return false;
	}
	private:
	static bool dfs(vector<vector<int>> &maze, int x, int y, int tx, int ty, vector<vector<int>> &sol){
		int N = maze.size();
		int M = maze[0].size();
		vector<int> dx = {-1,0,0,1};
		vector<int> dy = {0,-1,1,0};
		if(x < 0 || x >= N || y < 0 || y >= M || maze[x][y]!=0){
			return false;
		}
		if(x == tx && y == ty){
			sol[x][y]=9;
			return true;
		}
		else if(maze[x][y]==0){
			maze[x][y]='$';
			for(auto k(0); k < 4; ++k){
				if(dfs(maze,x+dx[k],y+dy[k],tx,ty,sol)){
					sol[x][y]=9;
					return true;
				}
			}
		}
		maze[x][y] = 1; // backtrack and unmark the current cell as visited
		return false;
	}
	static void printPath(vector<vector<int>> &maze){
		for(auto i(0); i < maze.size(); ++i){
			for(auto j(0); j < maze[0].size(); ++j){
				if(maze[i][j]==9){
					cout << " " << Yellow << maze[i][j] << Reset << " ";
				}
				else{
					cout << " " << maze[i][j] << " ";
				}
			}
			cout << "\n";
		}
		return;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	vector<vector<int>> maze = {{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
				    {1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
				    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				    {1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1},
				    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
				    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1},
				    {1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1},
				    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}};
	int N = maze.size();
	int M = maze[0].size();
	Solution::path(maze,0,1,N-1,M-2);
	return 0;
}
