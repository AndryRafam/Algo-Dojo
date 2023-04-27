/*
Given a 2D grid of characters and a list of words, find all the words that can be formed by traversing 
the grid in any of the 8 possible directions (up, down, left, right, and diagonals).

Time Complexity: O(W * M * N * L), where W is the number of words, M and N are the dimensions of the grid,
and L is the maximum length of a word.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive DFS
class Solution1{
    private:
    static bool dfs(vector<vector<char>> &grid, string word, int i, int j, int pos){
        if(pos==word.size()){
            return true;
        }
        if(i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j]!=word[pos]){
            return false;
        }
        else{
            vector<pair<int,int>> directions = {{-1, 0},{1, 0},{0, -1},{0, 1},{-1,1},{-1,-1},{1,1},{1,-1}};
            char temp = grid[i][j];
            grid[i][j] = '$';
            bool found = false;
            for(auto &dir : directions){
                int new_row = dir.first;
                int new_col = dir.second;
                if(dfs(grid,word,i+new_row,j+new_col,pos+1)){
                    found = true;
                    break;
                }
            }
            /*bool found = dfs(grid,word,i+1,j,pos+1) ||
                         dfs(grid,word,i-1,j,pos+1) ||
                         dfs(grid,word,i,j+1,pos+1) ||
                         dfs(grid,word,i,j-1,pos+1) ||
                         dfs(grid,word,i+1,j-1,pos+1) ||
                         dfs(grid,word,i+1,j+1,pos+1) ||
                         dfs(grid,word,i-1,j-1,pos+1) ||
                         dfs(grid,word,i-1,j+1,pos+1);*/
            grid[i][j] = temp; // backtrack and unmark cell as visited
            return found;
        }
    }
    public:
    static vector<string> wordSearch(vector<vector<char>> &grid, vector<string> words){
        unordered_set<string> ust;
        for(auto &word : words){
            for(auto i(0); i < grid.size(); ++i){
                for(auto j(0); j < grid[0].size(); ++j){
                    if(dfs(grid,word,i,j,0)){
                        ust.insert(word);
                    }
                }
            }
        }
        return vector<string>(ust.begin(),ust.end()); 
    }
};

/*Iterative DFS
class Solution2{
    private:
    static bool isValid(vector<vector<char>> &grid, string word, int x, int y, int k){
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y]!=word[k]){
            return false;
        }
        return true;
    }
    public:
    static bool DFS(vector<vector<char>> &grid, string word, pair<pair<int,int>,int> start){
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        stack<pair<pair<int,int>,int>> st;
        st.push(start);
        visited[start.first.first][start.first.second] = true;
        while(!st.empty()){
            auto cur = st.top();
            st.pop();
            if(cur.second==word.length()){
                return true;
            }
            vector<int> dx = {-1,0,0,1};
            vector<int> dy = {0,-1,1,0};
            for(auto k(0); k < 4; ++k){
                int newX = cur.first.first+dx[k];
                int newY = cur.first.second+dy[k];
                if(isValid(grid,word,newX,newY,cur.second) and !visited[newX][newY]){
                    visited[newX][newY] = true;
                    pair<pair<int,int>,int> next = {{newX,newY},cur.second+1};
                    st.push(next);
                }
            }
        }
        return false;
    }
};*/

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<char>> grid{{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    vector<string> words = {"ABCCED", "SEE"};
    for(auto &x : Solution1::wordSearch(grid,words)){
        cout << x << " ";
    }

    /*vector<vector<char>> board = {{'o','a','a','n'},
                                  {'e','t','a','e'},
                                  {'i','h','k','r'}, 
                                  {'i','f','l','v'}};

    vector<string> words = {"oath","pea","eat","rain"};
    unordered_set<string> ans;
    for(auto i(0); i < board.size(); ++i){
        for(auto j(0); j < board[0].size(); ++j){
            for(auto &word : words){
                pair<pair<int,int>,int> start = {{i,j},0};
                if(Solution2::DFS(board,word,start)){
                    ans.insert(word);
                }
            }
        }
    }
    if(ans.empty()){
        cout << "NOT FOUND" << endl;
    }
    else{
        for(auto &x : ans){
            cout << x << " ";
        }
    }
    return 0;*/

    return 0;
}
