/* Word search using DFS (Depth First Search Algorithm)
 * 
 * O(MxN) complexity */

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool exist(vector<vector<char>> &board, string word){
		for(auto i(0); i!=(int)board.size(); i++){
			for(auto j(0); j!=(int)board[i].size(); j++){
				if(dfs(board,word,i,j,0))
					return true;
			}
		}
		return false;
	}
	static bool dfs(vector<vector<char>> &board, string word, int i, int j, int k){
		if(i<0 || j<0 || i>=(int)board.size() || j>=(int)board[i].size())
			return false;
		if(board[i][j]==word[k]){
			char temp = board[i][j];
			if(k==(int)word.size()-1){
				return true;
			}
			else if(dfs(board,word,i-1,j,k+1) || dfs(board,word,i+1,j,k+1) 
					|| dfs(board,word,i,j-1,k+1) || dfs(board,word,i,j+1,k+1)){
					return true;
			}
			swap(board[i][j],temp);
		}
		return false;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<vector<char>> board = {{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
	string word = "abcced";
	cout << Solution::exist(board,word) << endl;
	return 0;
}
