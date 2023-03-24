/* Word search using DFS (Depth First Search Algorithm)
 * 
 * O(MxN) complexity */

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static bool exist(vector<vector<char>> &board, string word) {
		for(auto i(0); i!=(int)board.size(); ++i) {
			for(auto j(0); j!=(int)board[i].size(); ++j) {
				if(board[i][j]==word[0] && dfs(board,word,i,j,0)) {
					return true;
				}
			}
		}
		return false;
	}
	static bool dfs(vector<vector<char>> &board, string word, int i, int j, int k) {
		if(k==(int)word.size()) {
			return true;
		}
		if(i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[i].size() || board[i][j]!=word[k]) {
			return false;
		}
		char temp = board[i][j];
		board[i][j] = '$'; // mark after visit
		bool found = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
		board[i][j]=temp;
		return found;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<char>> board = {{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
	string word = "cced";
	cout << Solution::exist(board,word) << endl;
	return 0;
}
