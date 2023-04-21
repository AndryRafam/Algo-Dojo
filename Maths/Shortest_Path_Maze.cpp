/*
Shortest path in maze using BFS.

Four directions allowed.
*/

#include <bits/stdc++.h>
using namespace std;

//const int INF = numeric_limits<int>::max();

struct Node{ 
    int x,y,dist;
};

class Solution{
    private:
    static bool isValid(vector<vector<int>> &maze, int x, int y){
       return(x >= 0) && (x < maze.size()) && (y >= 0) && (y < maze[0].size()) && (maze[x][y]==0);
    }
    public:
    static int shortestPath(vector<vector<int>> &maze, Node &start, Node &end){
        // four directions
        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
        
        queue<Node> q;
        q.push(start);
        // mark starting node as visited
        visited[start.x][start.y] = true;

        // bfs traversal
        while(!q.empty()){
            Node curr = q.front();
            q.pop();

            if(curr.x == end.x && curr.y == end.y){
                return curr.dist;
            }
            // explore the four neighboring node
            for(auto &dir : directions){
                int newX = curr.x + dir.first;
                int newY = curr.y + dir.second;

                // check if the new Node is valid and not visited
                if(isValid(maze, newX, newY) && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    Node next = {newX, newY, curr.dist+1};
                    q.push(next);
                }
            }
        }
        //return INF;
        return -1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<int>> maze = {{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
								{1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
								{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
								{1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1},
								{1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
								{1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1},
								{1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1},};
    
    int M = maze.size();
    int N = maze[0].size();
    Node start = {0,1,0};
    Node end = {M-1,N-2,0};
	cout << Solution::shortestPath(maze,start,end) << endl; // 26
    return 0;
}
