/*
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions are allowed Up, Down, Right, Left.
*/ 

#include <bits/stdc++.h>
using namespace std;

#define Yellow "\x1B[33m"
#define Reset "\x1B[0m"

struct Cell{
	int x,y,dist;
};

// Recursive DFS
class Solution1 {
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
		int M = maze.size();
		int N = maze[0].size();
		vector<int> dx = {-1,0,0,1};
		vector<int> dy = {0,-1,1,0};
		if(x < 0 || x >= M || y < 0 || y >= N || maze[x][y]!=0){
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
			maze[x][y] = 0; // backtrack and unmark the current cell as visited
		}
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

// Iterative DFS
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

// BFS
class Solution3{
	private:
	static bool isValid(vector<vector<int>> maze, int x, int y){
		int m = maze.size();
		int n = maze[0].size();
		if(x < 0 or x >= m or y < 0 or y >= n or maze[x][y]!=0){
			return false;
		}
		return true;
	}
	public:
	static int BFS(vector<vector<int>> maze, Cell start, Cell goal){
		vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
		queue<Cell> q;
		q.push(start);
		visited[start.x][start.y]=true;
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			if(cur.x==goal.x and cur.y==goal.y){
				visited[cur.x][cur.y]=true;
				return cur.dist+1;
			}
			vector<int> dx = {-1,0,0,1};
			vector<int> dy = {0,-1,1,0};
			for(auto k(0); k < 4; ++k){
				int newx = cur.x+dx[k];
				int newy = cur.y+dy[k];
				if(isValid(maze,newx,newy) and !visited[newx][newy]){
					visited[newx][newy]=true;
					Cell next = {newx,newy,cur.dist+1};
					q.push(next);
				}
			}
		}
		return -1;
	}
};

/*Iterative DFS, alternative implementation
class Solution2{
	public:
	static bool DFS(vector<vector<int>> &maze, pair<int,int> start, pair<int,int> goal){
		vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
		stack<pair<int,int>> st;
		st.push(start);
		visited[start.first][start.second]=true;

		while(!st.empty()){
			auto cur = st.top();
			st.pop();
			if(cur.first==goal.first and cur.second==goal.second){
				return true;
			}
			vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
			for(auto &dir : directions){
				int newX = cur.first+dir.first;
				int newY = cur.second+dir.second;
				if(isValid(maze,newX,newY) && !visited[newX][newY]){
					visited[newX][newY] = true;
					pair<int,int> next = {newX,newY};
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
};*/

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
	
	int M = maze.size();
	int N = maze[0].size();
	Cell start = {0,1};
	Cell goal = {M-1,N-2};

	/*pair<int,int> start = {0,1};
	pair<int,int> goal = {m-1,n-2};*/

	//Solution1::path(maze,0,1,M-1,N-2);
	cout << (Solution2::DFS(maze,start,goal)==1 ? "True":"False") << endl;
	cout << Solution3::BFS(maze,start,goal) << endl;
	return 0;
}
