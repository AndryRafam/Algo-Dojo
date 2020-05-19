/* Maze Problem N°5: Starting from a random position within the maze,
 * 
 * find a path to get to the random target within the maze.
 * 
 * Return true if there is a path, false if not */

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool dfs(vector<vector<char>> &maze, int i, int j, int x, int y){
		int N = maze.size();
		int M = maze[0].size();
		if(i<0 || i>=N || j<0 || j>=M || maze[i][j]=='#')
			return false;
		if(maze[i][j]=='.' || maze[i][j]=='S' || maze[i][j]=='T'){ 
			maze[i][j]='#'; // mark as visited so we cannot visit anymore
			if(i==x && j==y){ // x and y are the target coordinate
				return true;
			}
			else if(dfs(maze,i+1,j,x,y) || dfs(maze,i-1,j,x,y) || dfs(maze,i,j+1,x,y) || dfs(maze,i,j-1,x,y)){
				return true;
			}
		}
		return false;
	}
	static bool find_path(vector<vector<char>> &maze, int Sx, int Sy, int Tx, int Ty){
		if(!dfs(maze,Sx,Sy,Tx,Ty))
			return false;
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<char>> maze = {{'#','#','#','#','#','#','#','#','#'},
				     {'#','.','.','.','.','.','.','S','#'},
				     {'#','.','#','.','#','#','#','#','#'},
				     {'#','.','.','.','#','.','.','.','#'},
				     {'#','.','#','#','#','#','#','.','#'},
				     {'#','.','.','.','.','.','.','.','#'},
				     {'#','.','#','#','#','#','#','.','#'},
				     {'#','.','#','T','.','.','.','.','#'},
				     {'#','#','#','#','#','#','#','#','#'}};
								 
	int Sx, Sy, Tx, Ty; // source and target coordinates
	
	int N = maze.size();
	int M = maze[0].size();
	
	for(auto i(0); i!=N; i++){
		for(auto j(0); j!=M; j++){
			if(maze[i][j]=='S'){
				Sx = i; Sy = j;
			}
			else if(maze[i][j]='T'){
				Tx = i; Ty = j;
			}
		}
	}
	cout << (Solution::find_path(maze,Sx,Sy,Tx,Ty)==1 ? "True":"False") << endl;
	return 0;
}
