/* Rat in a maze using simple backtracking
 * 
 * The rat can only go to right and down direction */
 
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool exist(vector<vector<int>> &maze){
		for(auto i(0); i!=(int)maze.size(); i++){
			for(auto j(0); j!=(int)maze[i].size(); j++){
				if(dfs(maze,i,j,0))
					return true;
			}
		}
		return false;
	}
	static bool dfs(vector<vector<int>> &maze, int i, int j, int k){
		int N = maze.size();
		int M = maze[0].size();
		
		if(i<0 || i>=N || j<0 || j>=M || maze[i][j]==0)
			return false;
		if(maze[i][j]==1){
			maze[i][j]='$'; // mark as visited so we can't visit anymore
			if(k==(N-1)+(M-1)) // bottom right corner
				return true;
			else if(dfs(maze,i+1,j,k+1) || dfs(maze,i,j+1,k+1)){
				return true;
			}
		}
		return false;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<int>> maze = {{1, 0, 0, 0, 0},
				    {1, 1, 0, 1, 0},
				    {0, 1, 1, 1, 0},
				    {0, 1, 1, 0, 0},
				    {1, 0, 1, 1, 1},
				    {0, 0, 0, 0, 1}};
								
	cout << (Solution::exist(maze)==1 ? "True":"False") << endl; // True for this example
	return 0;
}
