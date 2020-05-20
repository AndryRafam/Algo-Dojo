/* Lee algorithm */

#include <bits/stdc++.h>
using namespace std;

int row[]={-1,0,0,1};
int col[]={0,-1,1,0};

struct Point{
	int x, y;
};

struct queueNode{
	Point pt;
	int dist;
};

bool isValid(vector<vector<int>> &maze, int row, int col){
	int N = maze.size();
	int M = maze[0].size();
	if(row<0 || row>=N || col<0 || col>= M || maze[row][col]!=1)
		return false;
	return true;
}

int bfs(vector<vector<int>> &maze, Point src, Point dest){
		
	queue<queueNode> q;
	q.push({src,0});
	
	while(!q.empty()){
		queueNode curr = q.front();
		q.pop();
		
		if(curr.pt.x == dest.x && curr.pt.y == dest.y){ // current coordinates are equal to destination coordinates
			return curr.dist;
		}
				
		for(auto i(0); i!=4; i++){ // proceed to adjacency nodes
			if(isValid(maze,curr.pt.x+row[i],curr.pt.y+col[i])){
				maze[curr.pt.x+row[i]][curr.pt.y+col[i]]='#'; // mark as visited
				q.push({{curr.pt.x+row[i],curr.pt.y+col[i]},curr.dist+1});
			}
		}
	}
	return INT_MAX;
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<int>> maze = {{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
								{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
								{ 1, 1, 1, 2, 1, 1, 0, 1, 0, 1 }, 
								{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, 
								{ 0, 1, 1, 0, 1, 1, 1, 1, 1, 0 }, 
								{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
								{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 }, 
								{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 }, 
								{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 }};
								
	Point src = {0,0};
	Point dest = {8,9};
	
	cout << bfs(maze,src,dest) << endl; // 21
	return 0;
}
