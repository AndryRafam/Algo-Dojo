// PacMan A*search - HackerRank

#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x,y;
    double dist;
    bool operator < (const Cell& other) const { // operator overloading
        return dist > other.dist;
    }
};

double manhattan(int x1, int y1, int x2, int y2) { // heuristic function distance
    return abs(x1-x2)+abs(y1-y2);
}

bool isValid(vector<vector<char>> grid, int x, int y, int r, int c) {
    if(x > 0 && x < r && y > 0 && y < c && (grid[x][y]=='-' || grid[x][y]=='.')) {
        return true;
    }
    return false;
}

vector<pair<int,int>> aStarSearch(vector<vector<char>> grid, int r, int c, int pacman_r, int pacman_c, int food_r, int food_c) {
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    vector<vector<pair<int,int>>> parent(r,vector<pair<int,int>>(c,{-1,-1}));
    
    priority_queue<Cell> minHeap;

    Cell start{pacman_r,pacman_c,manhattan(pacman_r,pacman_c,food_r,food_c)};
    minHeap.push(start);
    visited[start.x][start.y] = true;

    while(!minHeap.empty()) {
        Cell curr = minHeap.top();
        minHeap.pop();
        if(curr.x==food_r && curr.y==food_c) {
            vector<pair<int,int>> path;
            while(!(curr.x==pacman_r && curr.y==pacman_c)) {
                path.push_back({curr.x,curr.y});
                tie(curr.x,curr.y) = parent[curr.x][curr.y];
            }
            path.push_back({pacman_r,pacman_c});
            reverse(path.begin(),path.end());
            return path;
        }
        for(auto &dir : directions) {
            int newX = curr.x+dir.first;
            int newY = curr.y+dir.second;
            if(isValid(grid,newX,newY,r,c) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                Cell next{newX,newY,manhattan(newX,newY,food_r,food_c)};
                minHeap.push(next);
                parent[newX][newY] = {curr.x,curr.y};
            }
        }
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int pacman_r,pacman_c;
    cin >> pacman_r >> pacman_c;
    int food_r,food_c;
    cin >> food_r >> food_c;
    int r,c;
    cin >> r >> c;
    vector<vector<char>> grid(r,vector<char>(c));
    for(int row = 0; row < r; ++row) {
        for(int col = 0; col < c; ++col) {
            cin >> grid[row][col];
        }
    }
    cout << "\n";
    vector<pair<int,int>> path = aStarSearch(grid,r,c,pacman_r,pacman_c,food_r,food_c);
    for(auto x : path) {
        cout << "(" << x.first << "," << x.second << ")" << "\n";
    }
    return 0;
}