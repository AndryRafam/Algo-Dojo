/*Best First Search algorithm - Optimal path finding in a maze.*/

#include <bits/stdc++.h>
using namespace std;

struct Cell{
    int x,y,distance;
    bool operator < (const Cell& other) const{
        return distance > other.distance;
    }
};

class Solution{
    private:
    static bool isValid(vector<vector<int>> &maze, int x, int y){
        if(x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size() || maze[x][y]!=0){
            return false;
        }
        return true;
    }
    static int heuristic(int x1, int y1, int x2, int y2){
        return abs(x2-x1)+abs(y2-y1); // manhattan distance; used when only 4 directions allowed.
    }
    public:
    static vector<Cell> A_star_Search(vector<vector<int>> &maze, int startX, int startY, int targetX, int targetY){
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
        priority_queue<Cell> pq;

        /*here, the first pair<int,int> represents the coordinates of the cell
        and the second pair<int,int> represents the coordinates of the parent cell.*/
        map<pair<int,int>,pair<int,int>> previous;

        Cell start{startX,startY,heuristic(startX,startY,targetX,targetY)};
        pq.push(start);
        visited[start.x][start.y] = true;

        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!pq.empty()){
            Cell current = pq.top();
            pq.pop();
            if(current.x==targetX && current.y==targetY){
                break;
            }
            for(auto &dir : directions){
                int newX = current.x+dir.first;
                int newY = current.y+dir.second;
                if(isValid(maze,newX,newY) && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    Cell next{newX, newY, heuristic(newX, newY, targetX, targetY)};
                    previous[{newX,newY}] = {current.x,current.y};
                    pq.push(next);
                }
            }
        }
        // reconstruct the optimal path
        vector<Cell> path;
        if(visited[targetX][targetY]){
            pair<int,int> current = {targetX,targetY};
            while(current != make_pair(startX,startY)){
                path.push_back({current.first,current.second,0});
                current = previous[current];
            }
            path.push_back({startX,startY,0});
            reverse(path.begin(),path.end());
        }
        return path;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<int>> maze = {
        {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1},
	{1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}
    };
    int M = maze.size();
    int N = maze[0].size();
    int startX = 0, startY = 1;
    int targetX = M-1, targetY = N-2;
    
    vector<Cell> path = Solution::A_star_Search(maze,startX,startY,targetX,targetY);
    
    cout << "\n";
    if(!path.empty()){
        for(auto &row : path){
            cout << row.x << " -> " << row.y << endl;
        }
    }
    return 0;
}
