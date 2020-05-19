/* Maze problem N°4: Starting from multiple point of the maze, check which one of them leads to the target.
 * 
 * The target is at the bottom right corner. */


#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool dfs(vector<vector<int>> &maze, int i, int j){
		int N = maze.size();
		int M = maze[0].size();
		if(i<0 || i>= N || j<0 || j>= M || maze[i][j]==0)
			return false;
		if(maze[i][j]==1 || maze[i][j]==2){ // start points are marked by number 2
			maze[i][j]='#';
			if(i==N-1 && j==M-1){
				return true;
			}
			else if(dfs(maze,i+1,j) || dfs(maze,i-1,j) || dfs(maze,i,j+1)
					|| dfs(maze,i,j-1)){
					return true;
			}
		}
		return false;
	}
	static bool exist(vector<vector<int>> &maze, int x, int y){
		if(!dfs(maze,x,y))
			return false;
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<int>> maze = {{2, 0, 0, 0, 0, 0},
								{1, 1, 0, 1, 1, 1},
								{0, 1, 1, 1, 0, 1},
								{0, 0, 1, 0, 1, 1},
								{2, 1, 0, 1, 1, 0},
								{0, 1, 0, 1, 0, 0},
								{0, 1, 0, 1, 1, 1}}; // 2 at position (0,0) leads to the target
								                     // 2 at position (4,0) doesn't lead to the target
								
	int N = maze.size();
	int M = maze[0].size();
	
	int Sx, Sy;
	
	for(auto i(0); i!=N; i++){
		for(auto j(0); j!=M; j++){
			if(maze[i][j]==2){
				Sx = i; Sy = j;
			}
			if(Solution::exist(maze,Sx,Sy)){
				cout << "Coordinates " << Sx << " " << Sy << " leads to the target" << endl; // (0,0) leads to the target
				break;
			}
		}
	}
	cout << endl;
	cout << "Coordinates " << Sx << " " << Sy << " doesn't lead to the target" << endl; // (4,0) doesn't lead to the target
	return 0;
}
