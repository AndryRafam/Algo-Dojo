/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells 
are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive DFS
class Solution1 {
	public:
	static string find(vector<vector<char>> &board, string word) {
		for(auto i(0); i!=(int)board.size(); ++i) {
			for(auto j(0); j!=(int)board[i].size(); ++j) {
				if(dfs(board,word,i,j,0)){
					return word;
				}
			}
		}
		return "NOT FOUND";
	}
	static bool dfs(vector<vector<char>> &board, string word, int i, int j, int k) {
		if(k==(int)word.size()) {
			return true;
		}
		if(i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[i].size() || board[i][j]!=word[k]) {
			return false;
		}
		else {
            char temp = board[i][j];
            board[i][j] = '$'; // mark as visited
            bool found = dfs(board,word,i+1,j,k+1) || 
						 		 dfs(board,word,i-1,j,k+1) || 
						 		 dfs(board,word,i,j+1,k+1) || 
						 		 dfs(board,word,i,j-1,k+1);
            board[i][j]=temp;
            return found;
		}
	}
};

// Iterative DFS
struct Node{
    int x,y,pos;
};

class Solution2{
    public:
    static bool DFS(vector<vector<char>> &grid, string word, Node start){
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        stack<Node> st;
        st.push(start);
        visited[start.x][start.y];
        while(!st.empty()){
            Node cur = st.top();
            st.pop();
            if(cur.pos==word.length()){
                cout << word << endl;
                return true;
            }
            vector<int> dx = {-1,0,0,1};
            vector<int> dy = {0,-1,1,0};
            for(auto k(0); k < 4; ++k){
                int newX = cur.x+dx[k];
                int newY = cur.y+dy[k];
                if(isValid(grid,newX,newY,word,cur.pos) and !visited[newX][newY]){
                    visited[newX][newY] = true;
                    Node next = {newX,newY,cur.pos+1};
                    st.push(next);
                }
            }
        }
        return false;
    }
    private:
    static bool isValid(vector<vector<char>> &grid, int x, int y, string word, int k){
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y]!=word[k]){
            return false;
        }
        return true;
    } 
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<char>> board = {{'a','b','c','e'},
				      {'s','f','c','s'},
				      {'a','d','e','e'}};
	string word = "css";
	//cout << Solution1::find(board,word);
	
	for(auto i(0); i < board.size(); ++i){
        for(auto j(0); j < board[0].size(); ++j){
            Node start = {i,j,0};
            if(Solution2::DFS(board,word,start)){
                return 0;
            }
        }
    }
    cout << "NOT FOUND" << endl;
	
	return 0;
}
