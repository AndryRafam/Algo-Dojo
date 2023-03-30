/*
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions are allowed Up, Down, Right, Left.
Print the solution if there is one, otherwise, print NO PATH.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool path(vector<vector<int>> &maze){
        vector<vector<int>> sol(maze.size(),vector<int>(maze[0].size(),0)); // solution matrix filled with 0, same size as maze
        if(dfs(maze,0,0,sol)){
            printPath(sol);
            return true;
        }
        cout << "NO PATH";
        return false;
    }
    private:
    static void printPath(vector<vector<int>> &maze){
        for(auto i(0); i < maze.size(); ++i){
            for(auto j(0); j < maze[0].size(); ++j){
                cout << " " << maze[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    static bool dfs(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &sol){
        int N = maze.size();
        int M = maze[0].size();
        vector<int> dx = {-1,0,0,1};
        vector<int> dy = {0,-1,1,0};
        if(x < 0 || x >= N || y < 0 || y >= M || maze[x][y]!=1){
            return false;
        }
        if(x==N-1 && y==M-1){
            sol[x][y]=1;
            return true;
        }
        else if(maze[x][y]==1){
            maze[x][y]='$';
            for(auto k(0); k < 4; ++k){
                if(dfs(maze,x+dx[k],y+dy[k],sol)){
                    sol[x][y]=1;
                    return true;
                }
            }
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
    Solution::path(maze);
    return 0;
}
