/*
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions are allowed Up, Down, Right, Left.
*/ 

#include <bits/stdc++.h>
using namespace std;

// Recursive DFS
class Solution1{
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
			maze[x][y] = 1; // backtrack and unmark the cell as visited
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

// Iterative DFS
struct Cell{
	int x,y;
};

class Solution2{
	public:
	static bool DFS(vector<vector<int>> &maze, Cell start, Cell goal){
		vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
		stack<Cell> st;
		st.push(start);
		visited[start.x][start.y]=true;

		while(!st.empty()){
			Cell cur = st.top();
			st.pop();
			if(cur.x==goal.x and cur.y==goal.y){
				return true;
			}
			vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
			for(auto &dir : directions){
				int newX = cur.x+dir.first;
				int newY = cur.y+dir.second;
				if(isValid(maze,newX,newY) && !visited[newX][newY]){
					visited[newX][newY] = true;
					Cell next = {newX,newY};
					st.push(next);
				}
			}
		}
		return false;
	}
	private:
	static bool isValid(vector<vector<int>> &maze, int x, int y){
		int m = maze.size();
		int n = maze[0].size();
		if(x < 0 or x >= m or y < 0 or y >= n or maze[x][y]!=0){
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
				    {0, 0, 1, 0, 1, 1}};
	
	vector<vector<int>> grid = {{1, 0, 0, 1, 1, 1},
				    {1, 1, 0, 1, 0, 1},
				    {0, 1, 1, 1, 0, 1},
				    {0, 0, 1, 0, 1, 1},
				    {0, 0, 1, 0, 1, 0},
				    {0, 0, 1, 0, 1, 1}};
								
	cout << (Solution1::path(maze)==1 ? "True":"False") << endl; // True
	cout << (Solution2::DFS(grid)==1 ? "True":"False") << endl; // True
	return 0;
}
