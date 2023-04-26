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

class Solution{
    public:
    static bool path(vector<vector<int>> &maze){
        //vector<vector<int>> sol(maze); // solution matrix filled with 0, same size as maze
        if(dfs(maze,0,0/*,sol*/)){
            printPath(maze);
            return true;
        }
        cout << "NO PATH";
        return false;
    }
    private:
    static void printPath(vector<vector<int>> &maze){
        for(auto i(0); i < maze.size(); ++i){
            for(auto j(0); j < maze[0].size(); ++j){
				if(maze[i][j]==9){
					cout << " " << Yellow << maze[i][j] << Reset << " ";
				}
				else {
					cout << " " << maze[i][j] << " ";
				}
            }
            cout << "\n\n";
        }
        return;
    }
    static bool dfs(vector<vector<int>> &maze, int x, int y/*,vector<vector<int>> &sol*/){
        int N = maze.size();
        int M = maze[0].size();
        vector<int> dx = {-1,0,0,1};
        vector<int> dy = {0,-1,1,0};
        if(x < 0 || x >= N || y < 0 || y >= M || maze[x][y]!=1){
            return false;
        }
        if(x==N-1 && y==M-1){
            //sol[x][y]=9; // mark path as 9
            maze[x][y]=9;
            return true;
        }
        else if(maze[x][y]==1){
            maze[x][y] = 9;
            for(auto k(0); k < 4; ++k){
                if(dfs(maze,x+dx[k],y+dy[k]/*,sol*/)){
                    //sol[x][y]=9; // mark path as 9
                    return true;
                }
	    }
	    maze[x][y] = 1; // backtrack and unmark the current cell as visited
	}
        return false;
    } 
};

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    vector<vector<int>> maze = {{1, 0, 0, 0, 0},
				{1, 0, 1, 1, 1},
				{1, 1, 1, 0, 1},
				{0, 0, 0, 1, 1},
				{1, 1, 0, 1, 0},
				{0, 0, 0, 1, 1}};
    cout << "\n";
    Solution::path(maze);
    return 0;
}
