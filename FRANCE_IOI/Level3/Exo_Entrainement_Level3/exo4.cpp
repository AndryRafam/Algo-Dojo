// BFS Approach TLE (time limit exceeded)
/*#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false)
#define pii pair<int,int>

bool isValid(vector<vector<int>> galerie, int x, int y, int H, int L) {
    return (x >= 0) && (x < H) && (y >= 0) && (y < L) && (galerie[x][y]==0);
}

void BFS(vector<vector<int>> galerie, int H, int L, int D, pair<pii,int> start, pair<pii,int> goal) {
    vector<vector<int>> res;
    vector<pii> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<bool>> visited(H,vector<bool>(L,false));
    queue<pair<pii,int>> q;
    q.push(start);
    visited[start.first.first][start.first.second]=true;
    int dist = start.second;
    dist = 0;

    while(!q.empty()) {
        dist++;
        auto curr = q.front();
        q.pop();
        if(dist%(D+1)==0) {
            cout << curr.first.first << " " << curr.first.second << "\n";
        }
        if(curr.first.first==goal.first.first && curr.first.second==goal.first.second) {
            return;
        }
        for(auto dir : directions) {
            int newX = curr.first.first+dir.first;
            int newY = curr.first.second+dir.second;
            if(isValid(galerie,newX,newY,H,L) && !visited[newX][newY]) {
                visited[newX][newY]=true;
                auto next = make_pair(make_pair(newX,newY),dist+1);
                q.push(next);
            }
        }
    }
    return;
}

int main() {
    fastio;
    cin.tie(0);
    int H,L,D; cin >> H >> L >> D;
    vector<vector<int>> galerie(H,vector<int>(L));
    pair<pii,int> start = {{0,0},0};
    pair<pii,int> goal = {{H-1,L-1},0};
    for(int h = 0; h < H; ++h) {
        for(int l = 0; l < L; ++l) {
            cin >> galerie[h][l];
        }
    }
    BFS(galerie,H,L,D,start,goal);
    return 0;
}*/

//DFS Approach
#include <bits/stdc++.h>
using namespace std;

int H, L, D;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> path;

void dfs(int i, int j) {
    visited[i][j] = true;
    path.push_back({i, j});

    if (i > 0 && grid[i-1][j] == 0 && !visited[i-1][j]) dfs(i-1, j);
    if (j > 0 && grid[i][j-1] == 0 && !visited[i][j-1]) dfs(i, j-1);
    if (i < H-1 && grid[i+1][j] == 0 && !visited[i+1][j]) dfs(i+1, j);
    if (j < L-1 && grid[i][j+1] == 0 && !visited[i][j+1]) dfs(i, j+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> H >> L >> D;
    grid.resize(H, vector<int>(L));
    visited.resize(H, vector<bool>(L, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < L; ++j) {
            cin >> grid[i][j];
        }
    }

    dfs(0, 0);

    for (int i = D; i < (int)path.size(); i += D+1) {
        cout << path[i].first << " " << path[i].second << "\n";
    }

    return 0;
}

