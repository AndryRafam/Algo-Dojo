/*
Given a 2D grid of characters and a list of words, find all the words that can be formed by traversing 
the grid in any of the 8 possible directions (up, down, left, right, and diagonals).

Time Complexity: O(W * M * N * L), where W is the number of words, M and N are the dimensions of the grid,
and L is the maximum length of a word.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
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
            grid[i][j] = temp;
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

int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<char>> grid{{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
    vector<string> words = {"ABCCED", "SEE"};
    for(auto &x : Solution::wordSearch(grid,words)){
        cout << x << " ";
    }
    return 0;
}
