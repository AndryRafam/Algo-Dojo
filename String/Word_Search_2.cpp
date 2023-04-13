/*
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
Brute force approach.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static vector<string> findWords(vector<vector<char>> &board, vector<string> &words){
        unordered_set<string> ust; // to ensure that there is no duplicate in the final result
        for(auto &word : words){
            for(auto i(0); i < board.size(); ++i){
                for(auto j(0); j < board[0].size(); ++j){
                    if(board[i][j]==word[0] && dfs(board,word,i,j,0)){
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
            board[i][j] = temp;
            return found; 
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<char>> board = {{'o','a','a','n'},
                                  {'e','t','a','e'},
                                  {'i','h','k','r'}, 
                                  {'i','f','l','v'}};

    vector<string> words = {"oath","pea","eat","rain"};
    for(auto &x : Solution::findWords(board,words)){
        cout << x << " ";
    }
    return 0;
}
