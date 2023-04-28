/*
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive DFS
class Solution1{
    public:
    static vector<string> findWords(vector<vector<char>> &board, vector<string> &words){
        unordered_set<string> ust; // to ensure that there is no duplicate in the final result
        for(auto &word : words){
            for(auto i(0); i < board.size(); ++i){
                for(auto j(0); j < board[0].size(); ++j){
                    if(dfs(board,word,i,j,0)){
                        ust.insert(word);
		    }
		}
	    }
	}
        return vector<string>(ust.begin(),ust.end());
    }
    private:
    static bool dfs(vector<vector<char>> &board, string word, int i, int j, int pos){
        if(pos==word.length()){
            return true;
        }
        if(i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[i].size() || board[i][j]!=word[pos]){
            return false;
        }
        else{
            char temp = board[i][j];
            board[i][j] = '$';
            bool found = dfs(board,word,i+1,j,pos+1) ||
                         dfs(board,word,i-1,j,pos+1) ||
                         dfs(board,word,i,j+1,pos+1) ||
                         dfs(board,word,i,j-1,pos+1);
            board[i][j] = temp; // backtrack and unmark cell as visited
            return found; 
        }
    }
};

//Iterative DFS
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
};

//BFS
class Solution3{
    public:
    static bool BFS(vector<vector<char>> &grid, string word, pair<pair<int,int>,int> start){
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<pair<int,int>,int>> Q;
        Q.push(start);
        visited[start.first.first][start.first.second] = true;
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            if(cur.second==word.length()){
                return true;
            }
            vector<pair<int,int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
            for(auto &dir : directions){
                int newX = cur.first.first+dir.first;
                int newY = cur.first.second+dir.second;
                if(isValid(grid,word,newX,newY,cur.second) and !visited[newX][newY]){
                    visited[newX][newY] = true;
                    pair<pair<int,int>,int> next = {{newX,newY},cur.second+1};
                    Q.push(next);
                }
            }
        }
        return false;
    }
    private:
    static bool isValid(vector<vector<char>> &grid, string word, int x, int y, int index){
        int m = grid.size();
        int n = grid[0].size();
        if(x >= 0 and x < m and y >= 0 and y < n and grid[x][y]==word[index]){
            return true;
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<char>> board = {{'o','a','a','n'},
                                  {'e','t','a','e'},
                                  {'i','h','k','r'}, 
                                  {'i','f','l','v'}};

    vector<string> words = {"oath","pea","eat","rain"};
    unordered_set<string> ans;
    /*for(auto &x : Solution1::findWords(board,words)){
        cout << x << " ";
    }*/

    /*for(auto i(0); i < board.size(); ++i){
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
    }*/
    
    for(auto i(0); i < board.size(); ++i){
        for(auto j(0); j < board[0].size(); ++j){
            for(auto &word : words){
                pair<pair<int,int>,int> start = {{i,j},0};
                if(Solution3::BFS(board,word,start)){
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
    return 0;
}

